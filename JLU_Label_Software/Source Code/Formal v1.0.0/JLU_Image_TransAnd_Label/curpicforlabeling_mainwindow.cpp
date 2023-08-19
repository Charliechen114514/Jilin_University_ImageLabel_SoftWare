<<<<<<< HEAD
#include "curpicforlabeling_mainwindow.h"
#include "ui_curpicforlabeling_mainwindow.h"
/**************************************************************************************************
*
*   funtions type :     basic_init
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      curPicForLabeling_MainWindow
*
*   Discriptions:       This function are used in
*
*                       1. basic class member params inits
*
*                       2. connecting and trigger others initialization
*
*                       3. ...
*
*   parameters :        QWidget *parent
*
*   return :            void
*
**************************************************************************************************/
curPicForLabeling_MainWindow::curPicForLabeling_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::curPicForLabeling_MainWindow)
{
    this->setWindowTitle("正在标注中...");
    ui->setupUi(this);
    /*预设定窗口显示的位置*/
    dialog = new labelQuerydialog;
    dialog->move(100,200);
    /*设定好默认保存的路径位置*/
    AlwaysLabelSavePath = "";
    AlwaysPictureSavePath = "";
    isAlwaysSaveConstPlaceForLabels = false;
    isAlwaysSaveConstPlaceForPics = false;
    /*关闭默认保存设置*/
    isAlreadyAutoDefSave = false;
    /*设置好默认的窗口*/
    setPenWidwindow = new setPenWidthWindows;
    setCurMaxPointCountWindows = new setOrShiftCurMaxPointCountsWindows;
    /*设置总是在窗顶*/
    setCurMaxPointCountWindows->setWindowModality(Qt::ApplicationModal);
    /*询问是否要保存在固定路径*/

    /*标签的*/
    if(QMessageBox::Yes == QMessageBox::question(this,"啊我不知道写什么窗口标题","要设置固定的标签保存路径嘛?")){
        setAlwaysSaveOnFixedPathForLabels();
        qDebug() << AlwaysLabelSavePath;
        isAlreadyAutoDefSave = true;
    }
    /*图像的*/
    if(QMessageBox::Yes == QMessageBox::question(this,"啊我不知道写什么窗口标题","要设置固定的图像保存路径嘛?")){
        setAlwaysSaveOnFixedPathForPics();
        qDebug() << AlwaysPictureSavePath;
        isAlreadyAutoDefSave = true;;
    }
    /*初始化画笔*/
    followLinePen.setWidth(USR_DEF_FOLLOWLINE_WIDTH);
    followLinePen.setColor(USR_DEF_FOLLOWLINE_COLOR);
    /*设定保存项为 否*/
    isSave = false;
    /*默认打开辅助标记*/
    isLabelHelperOpen = USR_DEF_LABEL_HELPER;
    mousePosRecorder = QPoint(0,0);
    this->centralWidget()->setMouseTracking(true);//开启鼠标实时追踪，监听鼠标移动事件，默认只有按下时才监听
    ticks = 0;
    curViewIndex = 0;
    initBasicConnection();
    /*显示这个窗口*/
    setCurMaxPointCountWindows->show();
}

/**************************************************************************************************
*
*   funtions type :     basic_init
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      initBasicConnection
*
*   Discriptions:       This function are used in
*
*                       1. init basic connections for mainWindow
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::initBasicConnection()
{
    /*链接：重新加载可能新产生的标签链表*/
    connect(dialog,&labelQuerydialog::finishSelectingLabel,
            this,&curPicForLabeling_MainWindow::reLoadLabelPairList);

    /*链接：每标记完一个轮廓刷新我们的最后的结果，等到用户表达结束或者返回的时候，直接返回拿到的数据*/
    connect(dialog,&labelQuerydialog::finishSelectingLabel,
            this,&curPicForLabeling_MainWindow::pushBackToFinalSigCurPicInfo);
    /*链接：取消设定，我们就要弹出一个先前做的更改*/
    connect(dialog,&labelQuerydialog::refuseSaving,this,&curPicForLabeling_MainWindow::removeTheLastPolyAndLabel);

    /*下面的三个信号与槽完成保存工作*/

    /*链接：只保存图片*/
    connect(ui->actionsavePicOnly,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::saveForResultCurPicButPicOnly);

    /*链接：只保存标签*/
    connect(ui->actionsaveLabelsOnly,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::saveForResultCurPicButLabelOnly);

    /*链接：都保存*/
    connect(ui->actionsaveAll,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::saveForResultCurPicAll);

    /*链接：切换颜色*/
    connect(ui->actionchangeColor,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::changeUsrCurPenColor);

    /*链接： 切换笔的宽度*/

    /*链接：链接更改标注画笔的粗度*/
    connect(ui->actionchangeWidth,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::showSetPenEidthWindow);
    /*链接：链接更改辅助标注画笔的粗度*/
    connect(ui->actionchangeHelperPenWidth,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::showSetPenEidthWindow);


    connect(ui->actionchangeAndActivateSelectMode,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::shiftAlwaysLabelInFixedMethod);

    /*链接：设置信号接受从而更改标记画笔的宽度*/
    connect(setPenWidwindow,&setPenWidthWindows::finishedEdit,
            this,&curPicForLabeling_MainWindow::changeUsrCurPenWidth);

    /*链接：设置信号接受从而更改标记辅助标记画笔的宽度*/
    connect(setPenWidwindow,&setPenWidthWindows::finishedEdit,
            this,&curPicForLabeling_MainWindow::changeFollowLinePenWidth);
    /*链接：关闭按钮链接*/
    connect(ui->actionendLabeling,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::close);

    connect(ui->action_removeLastPoint,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::removeTheLastSinglePoints);

    connect(ui->action_removeLastPoly,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::removeTheLastPolyAndLabel);
    /*链接：打开辅助标记*/
    connect(ui->actionopenTheLabelHelper,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::openModeOfLabelHelper);

    /*链接：关闭辅助标记*/
    connect(ui->actioncloseTheLabelHelper,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::closeModeOfLabelHelper);

    /*链接：改变辅助标记画笔颜色*/
    connect(ui->actionchangeHelperPenColor,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::changeFollowLinePenColor);

    /*链接：改变辅助标记画笔粗度*/
    connect(ui->actionchangeHelperPenWidth,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::changeFollowLinePenWidth);

    /*链接：切换到下一张*/
    connect(ui->actiontoAfterPic,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::moveToAfterPic);

    /*链接：完成编辑标注点个数最大值选择而触发初始化*/
    connect(setCurMaxPointCountWindows,&setOrShiftCurMaxPointCountsWindows::finishSelectAndReadyReturn,
            this,&curPicForLabeling_MainWindow::initCurMaxPointCount);
}

/**************************************************************************************************
*
*   funtions type :     basic_init
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      initLabelListFromManuallyLabelWindow
*
*   Discriptions:       This function are used in
*
*                       1. init labelLists from MainWindow
*
*   parameters :        QList<LabelPair> labelsget
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::initLabelListFromManuallyLabelWindow(QList<LabelPair> labelsget)
{
    labels = labelsget;
    dialog-> getTheCurrentLabelList(labels);
    dialog-> initTextLableShow();
    dialog-> showcheckedBoxListsSelections();

    // 这个模块是调试用的
    for(int i = 0 ;i < labels.size();i++){
        qDebug() << "这是初始标签：";
        qDebug() << labels[i].second;
    }

}

void curPicForLabeling_MainWindow::initCurUsrPenFromManuallyLabel(QPen pen)
{
    usrCurPen = pen;
}

void curPicForLabeling_MainWindow::initCurMaxPointCount()
{
    curAllowMaxPointsCount = setCurMaxPointCountWindows->returnFinalSeletionInCurMaxPointCount();
    isSaveShape = true;
}

// delete and release
curPicForLabeling_MainWindow::~curPicForLabeling_MainWindow()
{
    delete ui;
}

/**************************************************************************************************
*
*   funtions type :     basic_init
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      initPicturesListWithPicsPath
*
*   Discriptions:       This function are used in make initializations in pixmap
*
*   parameters :        QString curPath
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::initPicturesListWithPicsPath(QList<QString> curPathList)
{
    if(curPathList.empty())
    {
        QMessageBox::critical(this,"??","我很是好奇你是怎么到这里的！？");
        return;
    }
    WholeGroupPicsPathList = curPathList;
    pixmap.load(WholeGroupPicsPathList[0]);
    width_ratio = (float)pixmap.width()/this->width();
    height_ratio = (float)pixmap.height()/this->height();
    pixmap = pixmap.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    QPainter painter(&pixmap);
    this->resize(pixmap.size());
    painter.drawPixmap(0, 0, pixmap);
    update();
}

void curPicForLabeling_MainWindow::moveToAfterPic()
{
    curViewIndex++;
    if(curViewIndex >= WholeGroupPicsPathList.size()){
        QMessageBox::information(this,"注意！","你已经结束标注完了最后一张！");
        LABEL_SAVE_DEF_METHOD;
        return;
    }
    if(isSave == CCSTDC_JLU_IMAGE_LABLE_UNSAVE)
    {
        if(isAlreadyAutoDefSave)
        {

            LABEL_SAVE_DEF_METHOD;
            emit finishEveryThingAndReturnsTheNewLyLabelPair();
            emit refreshLabelMethod();
            finalSigCurPicInfo.first.clear();
            finalSigCurPicInfo.second.clear();
            goto FINISH_JUDGE;
        }
        if(QMessageBox::Yes == QMessageBox::question(this,"嗯？哪里跑？","小子跑路这快，不保存一下?不然会全部消失啊！点击确认以切到保存全部"))
        {
            LABEL_SAVE_DEF_METHOD;
            emit finishEveryThingAndReturnsTheNewLyLabelPair();
            emit refreshLabelMethod();
        }
    }
FINISH_JUDGE:
    finalSigCurPicInfo.first.clear();
    finalSigCurPicInfo.second.clear();
    curPicPoly.clear();
    pixmap.load(WholeGroupPicsPathList[curViewIndex]);
    width_ratio = (float)pixmap.width()/this->width();
    height_ratio = (float)pixmap.height()/this->height();
    pixmap = pixmap.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    QPainter painter(&pixmap);
    painter.drawPixmap(0, 0, pixmap);
    this->resize(pixmap.size());
    update();
}

/**************************************************************************************************
*
*   funtions type :     overLoad the virtual function
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      paintEvent
*
*   Discriptions:       This function are used in paint the pixs
*
*   parameters :        QPaintEvent* (no real params are needed!)
*
*   return :            void
*
**************************************************************************************************/

void curPicForLabeling_MainWindow::paintEvent(QPaintEvent*)
{
    setMouseTracking(true);
    QPixmap pix = pixmap.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    QPainter painter(&pix);
    painter.setPen(usrCurPen);
    switch(curAllowMaxPointsCount)
    {
        // special for standard Rects
    case CCSTDC_JLU_IMAGE_LABLE_STANDARD_RECT:
    {

        for(int i = 0; i < curPicPoly.size();i++)
        {
            QRect thisRect;
            thisRect.setTopLeft(curPicPoly[i][0]);
            thisRect.setBottomRight(curPicPoly[i][1]);
            painter.drawRect(thisRect);
            update();
        }

        painter.end();
        emit finishEditingPoints();
    }break;
    case CCSTDC_JLU_IMAGE_LABLE_ANYFOURPOLY:
    case CCSTDC_JLU_IMAGE_LABLE_ANYFIVEPOLY:
    default:
    {
        // qDebug() << curPicPoly.size();

        for(int i = 0; i < curPicPoly.size();i++)
        {
            painter.drawText(curPicPoly[i][0] + QPoint(LABEL_INDEX_TEXT_SHOW_OFFSET_X,LABEL_INDEX_TEXT_SHOW_OFFSET_Y),QString::number(i + 1));
            for(int j = 0; j < curPicPoly[i].size()-1;j++)
            {
               painter.drawLine(curPicPoly[i][j],curPicPoly[i][j + 1]);
            }
            painter.drawLine(curPicPoly[i][curPicPoly[i].size()-1],curPicPoly[i][0]);
            update();
        }
        for(int i = 1; i < tempPointsList.size();i++)
        {
            if(static_cast<unsigned int>(i) == curAllowMaxPointsCount - 1)
            {
               painter.drawLine(tempPointsList[i],tempPointsList[0]);
            }
            painter.drawLine(tempPointsList[i-1],tempPointsList[i]);
            update();
        }
        painter.end();
    }break;
    }
    painter.begin(this);//将当前窗体作为画布
    painter.drawPixmap(0, 0, pix);//将pixmap画到窗体
    /*刷新一下编辑过后的，如果用户保存直接取就好*/
    AfterEditedPixMap = pix;
    if(isLabelHelperOpen)
    {
        QPainter followLinePainter(this);
        followLinePainter.setPen(followLinePen);
        followLinePainter.drawLine(mousePosRecorder.x(),0,mousePosRecorder.x(),height());
        followLinePainter.drawLine(0,mousePosRecorder.y(),width(),mousePosRecorder.y());
        followLinePainter.end();
        update();
    }
}

/**************************************************************************************************
*
*   funtions type :     overLoad the virtual function
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      mousePressEvent
*
*   Discriptions:       This function are used in getting points by mouseClicking
*
*   parameters :        QMouseEvent *e
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(isSaveShape == CCSTDC_JLU_IMAGE_LABLE_UNSAVE)
    {
        QMessageBox::warning(this,"警告","知道你很急，但是你没有指定标注方法，拒绝标注");
        return;
    }
    if(e->button() == Qt::LeftButton){
        //qDebug() << " 左键摁下";

        switch(curAllowMaxPointsCount)
        {
        case 2:
        case 4:
        case 5:
        {
            if(ticks < curAllowMaxPointsCount - 1)
            {
                //qDebug() << "第"<< ticks <<"位置点已找好";
                //qDebug() << e->pos();
                ticks ++;
                tempPointsList.push_back(e->pos());
            }
            else
            {
                //qDebug() << "第"<< ticks <<"位置点已找好";
                //qDebug() << e->pos();
                ticks = 0;
                //curPicPoly.last().push_back(e->pos());
                tempPointsList.push_back(e->pos());
                curPicPoly.push_back(tempPointsList);
                tempPointsList.clear();
                dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
                dialog->setSeperator(seperator);
                update();
                dialog->show();
                isSave = CCSTDC_JLU_IMAGE_LABLE_UNSAVE;
            }
        }break;
        }
    }
}
/**************************************************************************************************
*
*   funtions type :     overLoad the virtual function
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      closeEvent
*
*   Discriptions:       This function are used in ensuring the save action
*
*   parameters :        QCloseEvent *e
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::closeEvent(QCloseEvent* events)
{
    if(isSave == CCSTDC_JLU_IMAGE_LABLE_UNSAVE){


        if(QMessageBox::Yes == QMessageBox::question(this,"嗯？哪里跑？","小子跑路这快，不保存一下?不然会全部消失啊！点击确认以切到保存全部"))
        {
            LABEL_SAVE_DEF_METHOD;
            emit finishEveryThingAndReturnsTheNewLyLabelPair();
            emit refreshLabelMethod();
            events->accept();
        }
        else
        {
            finalSigCurPicInfo.first.clear();
            finalSigCurPicInfo.second.clear();
            events->ignore();
        }
    }
    emit finishEveryThingAndReturnsTheNewLyLabelPair();
    emit refreshLabelMethod();
    events->accept();
}

/**************************************************************************************************
*
*   funtions type :     overLoad the virtual function
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      keyPressEvent
*
*   Discriptions:       This function are used in connecting the keyPress Event...
*                       Futher actions can be added here!
*
*   parameters :        QCloseEvent *e
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_Z && e->modifiers() == Qt::ControlModifier) //Ctrl+Z撤销
    {
        qDebug() << "Get the backword";
        removeTheLastPolyAndLabel();

    }
    else if(e->key() == Qt::Key_S && e->modifiers() == Qt::ControlModifier){
        LABEL_SAVE_DEF_METHOD;
    }
    else if(e->key() == Qt::Key_H && e->modifiers() == Qt::ControlModifier){
        changeModeOfLabelHelperDirect();
    }
    else if(e->key() == Qt::Key_A || e->key() == Qt::Key_Right){
        moveToAfterPic();
    }
    else if((e->key() == Qt::Key_Left && e->modifiers() == Qt::ControlModifier) || e->key() == Qt::Key_Backspace){
        removeTheLastSinglePoints();
    }
}

void curPicForLabeling_MainWindow::mouseMoveEvent(QMouseEvent* e)
{
    setMouseTracking(true);
    mousePosRecorder = e->pos();
}

void curPicForLabeling_MainWindow::wheelEvent(QWheelEvent* env)
{
    if(env->angleDelta().y() > 0){
        if(followLinePen.width() <= FOLLOWLINEPEN_WIDTH_MAX)
        {
            followLinePen.setWidth(followLinePen.width() + 1);
        }
    }
    else if(env->angleDelta().y() < 0)
    {
        if(followLinePen.width() >= FOLLOWLINEPEN_WIDTH_MIN)
        {
            followLinePen.setWidth(followLinePen.width() - 1);
        }
    }
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      reLoadLabelPairList
*
*   Discriptions:       get the labels on the labelqueryDialog
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::reLoadLabelPairList()
{
    LabelPair getLabel = dialog->returnFinalLabelToOutward();

    // 下面的for循环去重
    for(int i = 0; i < labels.size();i++){
        if(getLabel.second == labels[i].second){
            return;
        }
    }

    // 到这里了说明是新标签
    labels.push_back(getLabel);
}

void curPicForLabeling_MainWindow::pushBackToFinalSigCurPicInfo()
{

    finalSigCurPicInfo.first.push_back(curPicPoly.back());
    finalSigCurPicInfo.second.push_back(dialog->returnFinalLabelToOutward());

    // 调试一下
    qDebugTheLabelRes();
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeUsrCurPenColor
*
*   Discriptions:       change the pen color
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeUsrCurPenColor()
{
    // 生成QColorDialog并且调整位置，防止窗口堆积
    QColorDialog* newDialog = new QColorDialog;
    newDialog->move(100,200);

    // 拿到用户选择，然后删除之
    usrCurPen.setColor(newDialog->getColor());
    delete newDialog;
    newDialog = nullptr;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeFollowLinePenColor
*
*   Discriptions:       change the follow pen color
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeFollowLinePenColor()
{
    QColorDialog* newDialog = new QColorDialog;
    newDialog->move(100,200);

    followLinePen.setColor(newDialog->getColor());
    delete newDialog;
    newDialog = nullptr;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      showSetPenEidthWindow
*
*   Discriptions:       展示设置笔宽的Window
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::showSetPenEidthWindow()
{
    setPenWidwindow->setWindowFlag(Qt::WindowStaysOnTopHint);
    setPenWidwindow->show();
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeUsrCurPenWidth
*
*   Discriptions:       更改标注线笔宽
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeUsrCurPenWidth()
{
    usrCurPen.setWidth(setPenWidwindow->getFinalSetPenWidth());
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeFollowLinePenWidth
*
*   Discriptions:       更改辅助线笔宽
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeFollowLinePenWidth()
{
    followLinePen.setWidth(setPenWidwindow->getFinalSetPenWidth());
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      openModeOfLabelHelper
*
*   Discriptions:       打开自动标注
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::openModeOfLabelHelper()
{
    if(isLabelHelperOpen)
    {
        QMessageBox::warning(this,"喂喂喂","哥们已经开了别点了");
        return;
    }

    isLabelHelperOpen = true;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      closeModeOfLabelHelper
*
*   Discriptions:       关闭自动标注
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::closeModeOfLabelHelper()
{
    if(!isLabelHelperOpen)
    {
        QMessageBox::warning(this,"喂喂喂","哥们已经开了别点了");
        return;
    }

    isLabelHelperOpen = false;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeModeOfLabelHelperDirect
*
*   Discriptions:       切换辅助线显示
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeModeOfLabelHelperDirect()
{
    isLabelHelperOpen = !isLabelHelperOpen;
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      saveForResultCurPicButPicOnly
*
*   Discriptions:       保存图像
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::saveForResultCurPicButPicOnly()
{
    // 自动保存了，直接一波路径带走
    if(isAlwaysSaveConstPlaceForPics)
    {
        QString SavePath = AlwaysLabelSavePath +"/" + WholeGroupPicsPathList[curViewIndex - 1].split("/").last().split(".").first() + QString("_After_Labeled") +
                           + "." + WholeGroupPicsPathList[curViewIndex - 1].split("/").last().split(".").last();
        AfterEditedPixMap.save(SavePath);
        return;
    }

SAVEAGAIN:
    QString usrDefinedSavedPath = QFileDialog::getSaveFileName(this,tr("保存图像"),"./",tr("*.png;; *.jpg;; *.tif;;*.bmp"));
    if(usrDefinedSavedPath.isEmpty())
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"Ops！","你真的真的不保存嘛？"))
        {
            QMessageBox::information(this,"确认","放弃保存！");
            return;
        }
        else{
            goto SAVEAGAIN;
        }
    }

    if(!AfterEditedPixMap.save(usrDefinedSavedPath)){
        QMessageBox::critical(NULL,"出错了","T_T保存出错了！！！");
        if(QMessageBox::Yes == QMessageBox::question(this,"Ops！","你要放弃嘛?"))
        {
            QMessageBox::information(NULL,"确认","放弃保存！");
            return;
        }
        else{
            goto SAVEAGAIN;
        }

    }
    QMessageBox::information(this,"成功",QString("成功保存到！\n") + usrDefinedSavedPath);
    isSave = CCSTDC_JLU_IMAGE_LABLE_SAVE;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      saveForResultCurPicButPicOnly
*
*   Discriptions:       保存数据
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::saveForResultCurPicButLabelOnly()
{
    qDebug() << "进入保存例程";
    // qDebugTheLabelRes();
    QString resultToText = writingMethod();

    // 自动保存
    if(isAlwaysSaveConstPlaceForLabels)
    {
        qDebug() << curViewIndex - 1;
        if(curViewIndex - 1 < 0)
        {
            curViewIndex++;
        }
        qDebug() << WholeGroupPicsPathList.size();
        QString SavePath = AlwaysLabelSavePath +"/" + WholeGroupPicsPathList[curViewIndex - 1].split("/").last().split(".").first() + QString("_After_Labeled") +
                           + ".txt";
        qDebug() << SavePath;
        QFile fixedPathSaveFile(SavePath);
        if(fixedPathSaveFile.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QTextStream out(&fixedPathSaveFile);
            out << "";
            out << resultToText;
            fixedPathSaveFile.close();
        }
        return;
    }

    // 手动保存
SAVEAGAIN_LABLES:
    QString savePath = QFileDialog::getSaveFileName(this,"保存标签文件","./",".txt");
    if(savePath.isEmpty())
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"Ops！","你真的真的不保存嘛？"))
        {
            QMessageBox::information(this,"确认","放弃保存！");
            return;
        }
        else{
            goto SAVEAGAIN_LABLES;
        }
    }

    QFile saveFile(savePath) ;
    if(saveFile.open(QIODevice::ReadWrite|QIODevice::Text)){
        QString temp = resultToText; // 写入内容
        qDebug() << temp;
        // 将内容写入文件
        QTextStream out(&saveFile);
        out << temp;

        saveFile.close();
        isSave = CCSTDC_JLU_IMAGE_LABLE_SAVE;
        QMessageBox::information(this,"成功",QString("成功保存到！\n") + savePath);
    }else{
        QMessageBox::critical(NULL,"出错了","T_T保存出错了！！！");
        if(QMessageBox::Yes == QMessageBox::question(this,"Ops！","你要放弃嘛?"))
        {
            QMessageBox::information(this,"确认","放弃保存！");
            return;
        }
        else{
            savePath.clear();
            goto SAVEAGAIN_LABLES;
        }
    }

    return;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      saveForResultCurPicButPicOnly
*
*   Discriptions:       我全都要，我保保保
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::saveForResultCurPicAll()
{
    saveForResultCurPicButLabelOnly();
    saveForResultCurPicButPicOnly();
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      setAlwaysSaveOnFixedPathForLabels
*
*   Discriptions:       设置固定的保存标签的路径
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::setAlwaysSaveOnFixedPathForLabels()
{
    qDebug() << "标签保存选择"<< isAlwaysSaveConstPlaceForLabels;
    if(isAlwaysSaveConstPlaceForLabels)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你已经指定了固定标签保存路径，是打算更改嘛?"))
        {
            shiftAlwaysSaveOnFixedPathForLabels();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    AlwaysLabelSavePath = QFileDialog::getExistingDirectory(this,"选择文件夹","./");
    if(AlwaysLabelSavePath.isEmpty()){
        return;
    }

    isAlwaysSaveConstPlaceForLabels = true;
    qDebug() << "标签保存更改为选择了"<< isAlwaysSaveConstPlaceForLabels;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      shiftAlwaysSaveOnFixedPathForLabels
*
*   Discriptions:       更改固定的保存标签的路径
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::shiftAlwaysSaveOnFixedPathForLabels()
{

    if(!isAlwaysSaveConstPlaceForLabels)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你没有指定固定标签保存路径，指定嘛?"))
        {
            shiftAlwaysSaveOnFixedPathForLabels();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    AlwaysLabelSavePath = QFileDialog::getExistingDirectory(this,"选择文件夹","./");
    if(AlwaysLabelSavePath.isEmpty()){
        return;
    }

    isAlwaysSaveConstPlaceForLabels = true;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      setAlwaysSaveOnFixedPathForPics
*
*   Discriptions:       设置固定的保存图像的路径
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::setAlwaysSaveOnFixedPathForPics()
{
    qDebug() << "图片保存选择"<< isAlwaysSaveConstPlaceForPics;
    if(isAlwaysSaveConstPlaceForPics)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你已经指定了固定图像保存路径，是打算更改嘛?"))
        {
            shiftAlwaysSaveOnFixedPathForPics();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    AlwaysPictureSavePath = QFileDialog::getExistingDirectory(this,"选择文件夹","./");
    if(AlwaysPictureSavePath.isEmpty())
    {
        return;
    }

    isAlwaysSaveConstPlaceForPics = true;
    qDebug() << "图像先择更改为了" << isAlwaysSaveConstPlaceForPics;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      shiftAlwaysSaveOnFixedPathForPics
*
*   Discriptions:       更改固定的保存图像的路径
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::shiftAlwaysSaveOnFixedPathForPics()
{
    if(!isAlwaysSaveConstPlaceForPics)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你没有指定固定图像保存路径，指定嘛?"))
        {
            setAlwaysSaveOnFixedPathForPics();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    AlwaysPictureSavePath = QFileDialog::getExistingDirectory(this,"选择文件夹","./");
    if(AlwaysPictureSavePath.isEmpty())
    {
        return;
    }

    isAlwaysSaveConstPlaceForPics = true;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      setAlwaysLabelInFixedMethod
*
*   Discriptions:       设置是否固定标注方法
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::setAlwaysLabelInFixedMethod()
{
    if(isAlwaysSuchMethodOfLabeling)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你没有指定固定标注方法，指定嘛?"))
        {
            shiftAlwaysLabelInFixedMethod();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    isAlwaysSuchMethodOfLabeling = true;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      shiftAlwaysLabelInFixedMethod
*
*   Discriptions:       更改固定标注方法
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::shiftAlwaysLabelInFixedMethod()
{
    if(!isAlwaysSuchMethodOfLabeling)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你指定固定标注方法，更改嘛?\n这会导致当前所有数据的丢失！"))
        {
            finalSigCurPicInfo.first.clear();
            finalSigCurPicInfo.second.clear();
            curPicPoly.clear();

        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }
    qDebug() << "显示更改窗口";
    setCurMaxPointCountWindows->show();
    isAlwaysSuchMethodOfLabeling = true;
    update();
}

/**************************************************************************************************
*
*   funtions type :     DEBUG
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      qDebugTheLabelRes
*
*   Discriptions:       调 试 专 用
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::qDebugTheLabelRes()
{
    qDebug() << "有 "<<finalSigCurPicInfo.first.size() << "轮廓";
    for(int i = 0; i < finalSigCurPicInfo.first.size();i++)
    {
        //qDebug() << "这是第" << i << "个轮廓:";
        for(int j = 0; j < finalSigCurPicInfo.first[i].size();j++)
        {
            qDebug() << finalSigCurPicInfo.first[i][j];
        }
        qDebug() << "标签是:" << finalSigCurPicInfo.second[i].first<< ": "<< \
            finalSigCurPicInfo.second[i].second;
    }
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      removeTheLastSinglePoints
*
*   Discriptions:       移除上一个点
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::removeTheLastSinglePoints()
{
    if(tempPointsList.size() != 0)
    {
        tempPointsList.pop_back();
        ticks--;
        qDebug() << "已经撤销了单个点了";
    }
    update();
    return;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      removeTheLastPolyAndLabel
*
*   Discriptions:       移除上一个轮廓
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::removeTheLastPolyAndLabel()
{
    if(finalSigCurPicInfo.first.size()!= 0)
    {
        /*撤除保存数据*/
        finalSigCurPicInfo.first.pop_back();
        finalSigCurPicInfo.second.pop_back();
        /*撤出绘画的点*/
        curPicPoly.pop_back();
        qDebug() << "已撤销";
    }
    update();
    return;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      writingMethod
*
*   Discriptions:       标签写方法————哥们开摆了自己修改源码
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
QString curPicForLabeling_MainWindow::writingMethod()
{
    QString resultToText;

    for(int i = 0; i < finalSigCurPicInfo.first.size();i++)
    {
        resultToText += LABLE_TEXT_INDEX_PREFIX + QString::number(finalSigCurPicInfo.second[i].first) + \
                        LABLE_TEXT_INSERT_SLASH + LABLE_TEXT_LABLENAME_PREFIX + finalSigCurPicInfo.second[i].second + LABLE_TEXT_INSERT_SLASH;
        QString pointsSetShow = LABLE_TEXT_POINTSET_SHOW_PREFIX + LABLE_TEXT_INSERT_SLASH ;
        for(int j = 0 ; j < finalSigCurPicInfo.first[i].size(); j++)
        {
            pointsSetShow += LABLE_TEXT_POINT_SHOW_PREFIX + QString::number(finalSigCurPicInfo.first[i][j].x())\
                             + LABLE_TEXT_POINT_SPLIT + QString::number(finalSigCurPicInfo.first[i][j].y()) +LABLE_TEXT_POINT_SHOW_SUFFIX+ LABLE_TEXT_INSERT_SLASH;
        }
        pointsSetShow += LABLE_TEXT_POINTSET_END_SHOW + LABLE_TEXT_INSERT_SLASH ;
        resultToText += pointsSetShow;
    }

    return resultToText;
}



=======
#include "curpicforlabeling_mainwindow.h"
#include "ui_curpicforlabeling_mainwindow.h"
/**************************************************************************************************
*
*   funtions type :     basic_init
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      curPicForLabeling_MainWindow
*
*   Discriptions:       This function are used in
*
*                       1. basic class member params inits
*
*                       2. connecting and trigger others initialization
*
*                       3. ...
*
*   parameters :        QWidget *parent
*
*   return :            void
*
**************************************************************************************************/
curPicForLabeling_MainWindow::curPicForLabeling_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::curPicForLabeling_MainWindow)
{
    this->setWindowTitle("正在标注中...");
    ui->setupUi(this);
    /*预设定窗口显示的位置*/
    dialog = new labelQuerydialog;
    dialog->move(100,200);
    /*设定好默认保存的路径位置*/
    AlwaysLabelSavePath = "";
    AlwaysPictureSavePath = "";
    isAlwaysSaveConstPlaceForLabels = false;
    isAlwaysSaveConstPlaceForPics = false;
    /*关闭默认保存设置*/
    isAlreadyAutoDefSave = false;
    /*设置好默认的窗口*/
    setPenWidwindow = new setPenWidthWindows;
    setCurMaxPointCountWindows = new setOrShiftCurMaxPointCountsWindows;
    /*设置总是在窗顶*/
    setCurMaxPointCountWindows->setWindowModality(Qt::ApplicationModal);
    /*询问是否要保存在固定路径*/

    /*标签的*/
    if(QMessageBox::Yes == QMessageBox::question(this,"啊我不知道写什么窗口标题","要设置固定的标签保存路径嘛?")){
        setAlwaysSaveOnFixedPathForLabels();
        qDebug() << AlwaysLabelSavePath;
        isAlreadyAutoDefSave = true;
    }
    /*图像的*/
    if(QMessageBox::Yes == QMessageBox::question(this,"啊我不知道写什么窗口标题","要设置固定的图像保存路径嘛?")){
        setAlwaysSaveOnFixedPathForPics();
        qDebug() << AlwaysPictureSavePath;
        isAlreadyAutoDefSave = true;;
    }
    /*初始化画笔*/
    followLinePen.setWidth(USR_DEF_FOLLOWLINE_WIDTH);
    followLinePen.setColor(USR_DEF_FOLLOWLINE_COLOR);
    /*设定保存项为 否*/
    isSave = false;
    /*默认打开辅助标记*/
    isLabelHelperOpen = USR_DEF_LABEL_HELPER;
    mousePosRecorder = QPoint(0,0);
    this->centralWidget()->setMouseTracking(true);//开启鼠标实时追踪，监听鼠标移动事件，默认只有按下时才监听
    ticks = 0;
    curViewIndex = 0;
    initBasicConnection();
    /*显示这个窗口*/
    setCurMaxPointCountWindows->show();
}

/**************************************************************************************************
*
*   funtions type :     basic_init
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      initBasicConnection
*
*   Discriptions:       This function are used in
*
*                       1. init basic connections for mainWindow
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::initBasicConnection()
{
    /*链接：重新加载可能新产生的标签链表*/
    connect(dialog,&labelQuerydialog::finishSelectingLabel,
            this,&curPicForLabeling_MainWindow::reLoadLabelPairList);

    /*链接：每标记完一个轮廓刷新我们的最后的结果，等到用户表达结束或者返回的时候，直接返回拿到的数据*/
    connect(dialog,&labelQuerydialog::finishSelectingLabel,
            this,&curPicForLabeling_MainWindow::pushBackToFinalSigCurPicInfo);
    /*链接：取消设定，我们就要弹出一个先前做的更改*/
    connect(dialog,&labelQuerydialog::refuseSaving,this,&curPicForLabeling_MainWindow::removeTheLastPolyAndLabel);

    /*下面的三个信号与槽完成保存工作*/

    /*链接：只保存图片*/
    connect(ui->actionsavePicOnly,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::saveForResultCurPicButPicOnly);

    /*链接：只保存标签*/
    connect(ui->actionsaveLabelsOnly,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::saveForResultCurPicButLabelOnly);

    /*链接：都保存*/
    connect(ui->actionsaveAll,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::saveForResultCurPicAll);

    /*链接：切换颜色*/
    connect(ui->actionchangeColor,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::changeUsrCurPenColor);

    /*链接： 切换笔的宽度*/

    /*链接：链接更改标注画笔的粗度*/
    connect(ui->actionchangeWidth,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::showSetPenEidthWindow);
    /*链接：链接更改辅助标注画笔的粗度*/
    connect(ui->actionchangeHelperPenWidth,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::showSetPenEidthWindow);


    connect(ui->actionchangeAndActivateSelectMode,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::shiftAlwaysLabelInFixedMethod);

    /*链接：设置信号接受从而更改标记画笔的宽度*/
    connect(setPenWidwindow,&setPenWidthWindows::finishedEdit,
            this,&curPicForLabeling_MainWindow::changeUsrCurPenWidth);

    /*链接：设置信号接受从而更改标记辅助标记画笔的宽度*/
    connect(setPenWidwindow,&setPenWidthWindows::finishedEdit,
            this,&curPicForLabeling_MainWindow::changeFollowLinePenWidth);
    /*链接：关闭按钮链接*/
    connect(ui->actionendLabeling,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::close);

    connect(ui->action_removeLastPoint,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::removeTheLastSinglePoints);

    connect(ui->action_removeLastPoly,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::removeTheLastPolyAndLabel);
    /*链接：打开辅助标记*/
    connect(ui->actionopenTheLabelHelper,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::openModeOfLabelHelper);

    /*链接：关闭辅助标记*/
    connect(ui->actioncloseTheLabelHelper,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::closeModeOfLabelHelper);

    /*链接：改变辅助标记画笔颜色*/
    connect(ui->actionchangeHelperPenColor,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::changeFollowLinePenColor);

    /*链接：改变辅助标记画笔粗度*/
    connect(ui->actionchangeHelperPenWidth,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::changeFollowLinePenWidth);

    /*链接：切换到下一张*/
    connect(ui->actiontoAfterPic,&QAction::triggered,
            this,&curPicForLabeling_MainWindow::moveToAfterPic);

    /*链接：完成编辑标注点个数最大值选择而触发初始化*/
    connect(setCurMaxPointCountWindows,&setOrShiftCurMaxPointCountsWindows::finishSelectAndReadyReturn,
            this,&curPicForLabeling_MainWindow::initCurMaxPointCount);
}

/**************************************************************************************************
*
*   funtions type :     basic_init
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      initLabelListFromManuallyLabelWindow
*
*   Discriptions:       This function are used in
*
*                       1. init labelLists from MainWindow
*
*   parameters :        QList<LabelPair> labelsget
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::initLabelListFromManuallyLabelWindow(QList<LabelPair> labelsget)
{
    labels = labelsget;
    dialog-> getTheCurrentLabelList(labels);
    dialog-> initTextLableShow();
    dialog-> showcheckedBoxListsSelections();

    // 这个模块是调试用的
    for(int i = 0 ;i < labels.size();i++){
        qDebug() << "这是初始标签：";
        qDebug() << labels[i].second;
    }

}

void curPicForLabeling_MainWindow::initCurUsrPenFromManuallyLabel(QPen pen)
{
    usrCurPen = pen;
}

void curPicForLabeling_MainWindow::initCurMaxPointCount()
{
    curAllowMaxPointsCount = setCurMaxPointCountWindows->returnFinalSeletionInCurMaxPointCount();
    isSaveShape = true;
}

// delete and release
curPicForLabeling_MainWindow::~curPicForLabeling_MainWindow()
{
    delete ui;
}

/**************************************************************************************************
*
*   funtions type :     basic_init
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      initPicturesListWithPicsPath
*
*   Discriptions:       This function are used in make initializations in pixmap
*
*   parameters :        QString curPath
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::initPicturesListWithPicsPath(QList<QString> curPathList)
{
    if(curPathList.empty())
    {
        QMessageBox::critical(this,"??","我很是好奇你是怎么到这里的！？");
        return;
    }
    WholeGroupPicsPathList = curPathList;
    pixmap.load(WholeGroupPicsPathList[0]);
    width_ratio = (float)pixmap.width()/this->width();
    height_ratio = (float)pixmap.height()/this->height();
    pixmap = pixmap.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    QPainter painter(&pixmap);
    this->resize(pixmap.size());
    painter.drawPixmap(0, 0, pixmap);
    update();
}

void curPicForLabeling_MainWindow::moveToAfterPic()
{
    curViewIndex++;
    if(curViewIndex >= WholeGroupPicsPathList.size()){
        QMessageBox::information(this,"注意！","你已经结束标注完了最后一张！");
        LABEL_SAVE_DEF_METHOD;
        return;
    }
    if(isSave == CCSTDC_JLU_IMAGE_LABLE_UNSAVE)
    {
        if(isAlreadyAutoDefSave)
        {

            LABEL_SAVE_DEF_METHOD;
            emit finishEveryThingAndReturnsTheNewLyLabelPair();
            emit refreshLabelMethod();
            finalSigCurPicInfo.first.clear();
            finalSigCurPicInfo.second.clear();
            goto FINISH_JUDGE;
        }
        if(QMessageBox::Yes == QMessageBox::question(this,"嗯？哪里跑？","小子跑路这快，不保存一下?不然会全部消失啊！点击确认以切到保存全部"))
        {
            LABEL_SAVE_DEF_METHOD;
            emit finishEveryThingAndReturnsTheNewLyLabelPair();
            emit refreshLabelMethod();
        }
    }
FINISH_JUDGE:
    finalSigCurPicInfo.first.clear();
    finalSigCurPicInfo.second.clear();
    curPicPoly.clear();
    pixmap.load(WholeGroupPicsPathList[curViewIndex]);
    width_ratio = (float)pixmap.width()/this->width();
    height_ratio = (float)pixmap.height()/this->height();
    pixmap = pixmap.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    QPainter painter(&pixmap);
    painter.drawPixmap(0, 0, pixmap);
    this->resize(pixmap.size());
    update();
}

/**************************************************************************************************
*
*   funtions type :     overLoad the virtual function
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      paintEvent
*
*   Discriptions:       This function are used in paint the pixs
*
*   parameters :        QPaintEvent* (no real params are needed!)
*
*   return :            void
*
**************************************************************************************************/

void curPicForLabeling_MainWindow::paintEvent(QPaintEvent*)
{
    setMouseTracking(true);
    QPixmap pix = pixmap.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    QPainter painter(&pix);
    painter.setPen(usrCurPen);
    switch(curAllowMaxPointsCount)
    {
        // special for standard Rects
    case CCSTDC_JLU_IMAGE_LABLE_STANDARD_RECT:
    {

        for(int i = 0; i < curPicPoly.size();i++)
        {
            QRect thisRect;
            thisRect.setTopLeft(curPicPoly[i][0]);
            thisRect.setBottomRight(curPicPoly[i][1]);
            painter.drawRect(thisRect);
            update();
        }

        painter.end();
        emit finishEditingPoints();
    }break;
    case CCSTDC_JLU_IMAGE_LABLE_ANYFOURPOLY:
    case CCSTDC_JLU_IMAGE_LABLE_ANYFIVEPOLY:
    default:
    {
        // qDebug() << curPicPoly.size();

        for(int i = 0; i < curPicPoly.size();i++)
        {
            painter.drawText(curPicPoly[i][0] + QPoint(LABEL_INDEX_TEXT_SHOW_OFFSET_X,LABEL_INDEX_TEXT_SHOW_OFFSET_Y),QString::number(i + 1));
            for(int j = 0; j < curPicPoly[i].size()-1;j++)
            {
               painter.drawLine(curPicPoly[i][j],curPicPoly[i][j + 1]);
            }
            painter.drawLine(curPicPoly[i][curPicPoly[i].size()-1],curPicPoly[i][0]);
            update();
        }
        for(int i = 1; i < tempPointsList.size();i++)
        {
            if(static_cast<unsigned int>(i) == curAllowMaxPointsCount - 1)
            {
               painter.drawLine(tempPointsList[i],tempPointsList[0]);
            }
            painter.drawLine(tempPointsList[i-1],tempPointsList[i]);
            update();
        }
        painter.end();
    }break;
    }
    painter.begin(this);//将当前窗体作为画布
    painter.drawPixmap(0, 0, pix);//将pixmap画到窗体
    /*刷新一下编辑过后的，如果用户保存直接取就好*/
    AfterEditedPixMap = pix;
    if(isLabelHelperOpen)
    {
        QPainter followLinePainter(this);
        followLinePainter.setPen(followLinePen);
        followLinePainter.drawLine(mousePosRecorder.x(),0,mousePosRecorder.x(),height());
        followLinePainter.drawLine(0,mousePosRecorder.y(),width(),mousePosRecorder.y());
        followLinePainter.end();
        update();
    }
}

/**************************************************************************************************
*
*   funtions type :     overLoad the virtual function
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      mousePressEvent
*
*   Discriptions:       This function are used in getting points by mouseClicking
*
*   parameters :        QMouseEvent *e
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(isSaveShape == CCSTDC_JLU_IMAGE_LABLE_UNSAVE)
    {
        QMessageBox::warning(this,"警告","知道你很急，但是你没有指定标注方法，拒绝标注");
        return;
    }
    if(e->button() == Qt::LeftButton){
        //qDebug() << " 左键摁下";

        switch(curAllowMaxPointsCount)
        {
        case 2:
        case 4:
        case 5:
        {
            if(ticks < curAllowMaxPointsCount - 1)
            {
                //qDebug() << "第"<< ticks <<"位置点已找好";
                //qDebug() << e->pos();
                ticks ++;
                tempPointsList.push_back(e->pos());
            }
            else
            {
                //qDebug() << "第"<< ticks <<"位置点已找好";
                //qDebug() << e->pos();
                ticks = 0;
                //curPicPoly.last().push_back(e->pos());
                tempPointsList.push_back(e->pos());
                curPicPoly.push_back(tempPointsList);
                tempPointsList.clear();
                dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
                dialog->setSeperator(seperator);
                update();
                dialog->show();
                isSave = CCSTDC_JLU_IMAGE_LABLE_UNSAVE;
            }
        }break;
        }
    }
}
/**************************************************************************************************
*
*   funtions type :     overLoad the virtual function
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      closeEvent
*
*   Discriptions:       This function are used in ensuring the save action
*
*   parameters :        QCloseEvent *e
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::closeEvent(QCloseEvent* events)
{
    if(isSave == CCSTDC_JLU_IMAGE_LABLE_UNSAVE){


        if(QMessageBox::Yes == QMessageBox::question(this,"嗯？哪里跑？","小子跑路这快，不保存一下?不然会全部消失啊！点击确认以切到保存全部"))
        {
            LABEL_SAVE_DEF_METHOD;
            emit finishEveryThingAndReturnsTheNewLyLabelPair();
            emit refreshLabelMethod();
            events->accept();
        }
        else
        {
            finalSigCurPicInfo.first.clear();
            finalSigCurPicInfo.second.clear();
            events->ignore();
        }
    }
    emit finishEveryThingAndReturnsTheNewLyLabelPair();
    emit refreshLabelMethod();
    events->accept();
}

/**************************************************************************************************
*
*   funtions type :     overLoad the virtual function
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      keyPressEvent
*
*   Discriptions:       This function are used in connecting the keyPress Event...
*                       Futher actions can be added here!
*
*   parameters :        QCloseEvent *e
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_Z && e->modifiers() == Qt::ControlModifier) //Ctrl+Z撤销
    {
        qDebug() << "Get the backword";
        removeTheLastPolyAndLabel();

    }
    else if(e->key() == Qt::Key_S && e->modifiers() == Qt::ControlModifier){
        LABEL_SAVE_DEF_METHOD;
    }
    else if(e->key() == Qt::Key_H && e->modifiers() == Qt::ControlModifier){
        changeModeOfLabelHelperDirect();
    }
    else if(e->key() == Qt::Key_A || e->key() == Qt::Key_Right){
        moveToAfterPic();
    }
    else if((e->key() == Qt::Key_Left && e->modifiers() == Qt::ControlModifier) || e->key() == Qt::Key_Backspace){
        removeTheLastSinglePoints();
    }
}

void curPicForLabeling_MainWindow::mouseMoveEvent(QMouseEvent* e)
{
    setMouseTracking(true);
    mousePosRecorder = e->pos();
}

void curPicForLabeling_MainWindow::wheelEvent(QWheelEvent* env)
{
    if(env->angleDelta().y() > 0){
        if(followLinePen.width() <= FOLLOWLINEPEN_WIDTH_MAX)
        {
            followLinePen.setWidth(followLinePen.width() + 1);
        }
    }
    else if(env->angleDelta().y() < 0)
    {
        if(followLinePen.width() >= FOLLOWLINEPEN_WIDTH_MIN)
        {
            followLinePen.setWidth(followLinePen.width() - 1);
        }
    }
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      reLoadLabelPairList
*
*   Discriptions:       get the labels on the labelqueryDialog
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::reLoadLabelPairList()
{
    LabelPair getLabel = dialog->returnFinalLabelToOutward();

    // 下面的for循环去重
    for(int i = 0; i < labels.size();i++){
        if(getLabel.second == labels[i].second){
            return;
        }
    }

    // 到这里了说明是新标签
    labels.push_back(getLabel);
}

void curPicForLabeling_MainWindow::pushBackToFinalSigCurPicInfo()
{

    finalSigCurPicInfo.first.push_back(curPicPoly.back());
    finalSigCurPicInfo.second.push_back(dialog->returnFinalLabelToOutward());

    // 调试一下
    qDebugTheLabelRes();
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeUsrCurPenColor
*
*   Discriptions:       change the pen color
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeUsrCurPenColor()
{
    // 生成QColorDialog并且调整位置，防止窗口堆积
    QColorDialog* newDialog = new QColorDialog;
    newDialog->move(100,200);

    // 拿到用户选择，然后删除之
    usrCurPen.setColor(newDialog->getColor());
    delete newDialog;
    newDialog = nullptr;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeFollowLinePenColor
*
*   Discriptions:       change the follow pen color
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeFollowLinePenColor()
{
    QColorDialog* newDialog = new QColorDialog;
    newDialog->move(100,200);

    followLinePen.setColor(newDialog->getColor());
    delete newDialog;
    newDialog = nullptr;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      showSetPenEidthWindow
*
*   Discriptions:       展示设置笔宽的Window
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::showSetPenEidthWindow()
{
    setPenWidwindow->setWindowFlag(Qt::WindowStaysOnTopHint);
    setPenWidwindow->show();
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeUsrCurPenWidth
*
*   Discriptions:       更改标注线笔宽
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeUsrCurPenWidth()
{
    usrCurPen.setWidth(setPenWidwindow->getFinalSetPenWidth());
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeFollowLinePenWidth
*
*   Discriptions:       更改辅助线笔宽
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeFollowLinePenWidth()
{
    followLinePen.setWidth(setPenWidwindow->getFinalSetPenWidth());
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      openModeOfLabelHelper
*
*   Discriptions:       打开自动标注
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::openModeOfLabelHelper()
{
    if(isLabelHelperOpen)
    {
        QMessageBox::warning(this,"喂喂喂","哥们已经开了别点了");
        return;
    }

    isLabelHelperOpen = true;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      closeModeOfLabelHelper
*
*   Discriptions:       关闭自动标注
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::closeModeOfLabelHelper()
{
    if(!isLabelHelperOpen)
    {
        QMessageBox::warning(this,"喂喂喂","哥们已经开了别点了");
        return;
    }

    isLabelHelperOpen = false;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      changeModeOfLabelHelperDirect
*
*   Discriptions:       切换辅助线显示
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::changeModeOfLabelHelperDirect()
{
    isLabelHelperOpen = !isLabelHelperOpen;
}


/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      saveForResultCurPicButPicOnly
*
*   Discriptions:       保存图像
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::saveForResultCurPicButPicOnly()
{
    // 自动保存了，直接一波路径带走
    if(isAlwaysSaveConstPlaceForPics)
    {
        QString SavePath = AlwaysLabelSavePath +"/" + WholeGroupPicsPathList[curViewIndex - 1].split("/").last().split(".").first() + QString("_After_Labeled") +
                           + "." + WholeGroupPicsPathList[curViewIndex - 1].split("/").last().split(".").last();
        AfterEditedPixMap.save(SavePath);
        return;
    }

SAVEAGAIN:
    QString usrDefinedSavedPath = QFileDialog::getSaveFileName(this,tr("保存图像"),"./",tr("*.png;; *.jpg;; *.tif;;*.bmp"));
    if(usrDefinedSavedPath.isEmpty())
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"Ops！","你真的真的不保存嘛？"))
        {
            QMessageBox::information(this,"确认","放弃保存！");
            return;
        }
        else{
            goto SAVEAGAIN;
        }
    }

    if(!AfterEditedPixMap.save(usrDefinedSavedPath)){
        QMessageBox::critical(NULL,"出错了","T_T保存出错了！！！");
        if(QMessageBox::Yes == QMessageBox::question(this,"Ops！","你要放弃嘛?"))
        {
            QMessageBox::information(NULL,"确认","放弃保存！");
            return;
        }
        else{
            goto SAVEAGAIN;
        }

    }
    QMessageBox::information(this,"成功",QString("成功保存到！\n") + usrDefinedSavedPath);
    isSave = CCSTDC_JLU_IMAGE_LABLE_SAVE;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      saveForResultCurPicButPicOnly
*
*   Discriptions:       保存数据
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::saveForResultCurPicButLabelOnly()
{
    qDebug() << "进入保存例程";
    // qDebugTheLabelRes();
    QString resultToText = writingMethod();

    // 自动保存
    if(isAlwaysSaveConstPlaceForLabels)
    {
        qDebug() << curViewIndex - 1;
        if(curViewIndex - 1 < 0)
        {
            curViewIndex++;
        }
        qDebug() << WholeGroupPicsPathList.size();
        QString SavePath = AlwaysLabelSavePath +"/" + WholeGroupPicsPathList[curViewIndex - 1].split("/").last().split(".").first() + QString("_After_Labeled") +
                           + ".txt";
        qDebug() << SavePath;
        QFile fixedPathSaveFile(SavePath);
        if(fixedPathSaveFile.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QTextStream out(&fixedPathSaveFile);
            out << "";
            out << resultToText;
            fixedPathSaveFile.close();
        }
        return;
    }

    // 手动保存
SAVEAGAIN_LABLES:
    QString savePath = QFileDialog::getSaveFileName(this,"保存标签文件","./",".txt");
    if(savePath.isEmpty())
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"Ops！","你真的真的不保存嘛？"))
        {
            QMessageBox::information(this,"确认","放弃保存！");
            return;
        }
        else{
            goto SAVEAGAIN_LABLES;
        }
    }

    QFile saveFile(savePath) ;
    if(saveFile.open(QIODevice::ReadWrite|QIODevice::Text)){
        QString temp = resultToText; // 写入内容
        qDebug() << temp;
        // 将内容写入文件
        QTextStream out(&saveFile);
        out << temp;

        saveFile.close();
        isSave = CCSTDC_JLU_IMAGE_LABLE_SAVE;
        QMessageBox::information(this,"成功",QString("成功保存到！\n") + savePath);
    }else{
        QMessageBox::critical(NULL,"出错了","T_T保存出错了！！！");
        if(QMessageBox::Yes == QMessageBox::question(this,"Ops！","你要放弃嘛?"))
        {
            QMessageBox::information(this,"确认","放弃保存！");
            return;
        }
        else{
            savePath.clear();
            goto SAVEAGAIN_LABLES;
        }
    }

    return;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      saveForResultCurPicButPicOnly
*
*   Discriptions:       我全都要，我保保保
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::saveForResultCurPicAll()
{
    saveForResultCurPicButLabelOnly();
    saveForResultCurPicButPicOnly();
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      setAlwaysSaveOnFixedPathForLabels
*
*   Discriptions:       设置固定的保存标签的路径
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::setAlwaysSaveOnFixedPathForLabels()
{
    qDebug() << "标签保存选择"<< isAlwaysSaveConstPlaceForLabels;
    if(isAlwaysSaveConstPlaceForLabels)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你已经指定了固定标签保存路径，是打算更改嘛?"))
        {
            shiftAlwaysSaveOnFixedPathForLabels();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    AlwaysLabelSavePath = QFileDialog::getExistingDirectory(this,"选择文件夹","./");
    if(AlwaysLabelSavePath.isEmpty()){
        return;
    }

    isAlwaysSaveConstPlaceForLabels = true;
    qDebug() << "标签保存更改为选择了"<< isAlwaysSaveConstPlaceForLabels;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      shiftAlwaysSaveOnFixedPathForLabels
*
*   Discriptions:       更改固定的保存标签的路径
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::shiftAlwaysSaveOnFixedPathForLabels()
{

    if(!isAlwaysSaveConstPlaceForLabels)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你没有指定固定标签保存路径，指定嘛?"))
        {
            shiftAlwaysSaveOnFixedPathForLabels();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    AlwaysLabelSavePath = QFileDialog::getExistingDirectory(this,"选择文件夹","./");
    if(AlwaysLabelSavePath.isEmpty()){
        return;
    }

    isAlwaysSaveConstPlaceForLabels = true;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      setAlwaysSaveOnFixedPathForPics
*
*   Discriptions:       设置固定的保存图像的路径
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::setAlwaysSaveOnFixedPathForPics()
{
    qDebug() << "图片保存选择"<< isAlwaysSaveConstPlaceForPics;
    if(isAlwaysSaveConstPlaceForPics)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你已经指定了固定图像保存路径，是打算更改嘛?"))
        {
            shiftAlwaysSaveOnFixedPathForPics();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    AlwaysPictureSavePath = QFileDialog::getExistingDirectory(this,"选择文件夹","./");
    if(AlwaysPictureSavePath.isEmpty())
    {
        return;
    }

    isAlwaysSaveConstPlaceForPics = true;
    qDebug() << "图像先择更改为了" << isAlwaysSaveConstPlaceForPics;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      shiftAlwaysSaveOnFixedPathForPics
*
*   Discriptions:       更改固定的保存图像的路径
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::shiftAlwaysSaveOnFixedPathForPics()
{
    if(!isAlwaysSaveConstPlaceForPics)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你没有指定固定图像保存路径，指定嘛?"))
        {
            setAlwaysSaveOnFixedPathForPics();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    AlwaysPictureSavePath = QFileDialog::getExistingDirectory(this,"选择文件夹","./");
    if(AlwaysPictureSavePath.isEmpty())
    {
        return;
    }

    isAlwaysSaveConstPlaceForPics = true;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      setAlwaysLabelInFixedMethod
*
*   Discriptions:       设置是否固定标注方法
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::setAlwaysLabelInFixedMethod()
{
    if(isAlwaysSuchMethodOfLabeling)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你没有指定固定标注方法，指定嘛?"))
        {
            shiftAlwaysLabelInFixedMethod();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }

    isAlwaysSuchMethodOfLabeling = true;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      shiftAlwaysLabelInFixedMethod
*
*   Discriptions:       更改固定标注方法
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::shiftAlwaysLabelInFixedMethod()
{
    if(!isAlwaysSuchMethodOfLabeling)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"表示历史决议的若干疑惑","可是你指定固定标注方法，更改嘛?\n这会导致当前所有数据的丢失！"))
        {
            finalSigCurPicInfo.first.clear();
            finalSigCurPicInfo.second.clear();
            curPicPoly.clear();

        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }
    qDebug() << "显示更改窗口";
    setCurMaxPointCountWindows->show();
    isAlwaysSuchMethodOfLabeling = true;
    update();
}

/**************************************************************************************************
*
*   funtions type :     DEBUG
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      qDebugTheLabelRes
*
*   Discriptions:       调 试 专 用
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::qDebugTheLabelRes()
{
    qDebug() << "有 "<<finalSigCurPicInfo.first.size() << "轮廓";
    for(int i = 0; i < finalSigCurPicInfo.first.size();i++)
    {
        //qDebug() << "这是第" << i << "个轮廓:";
        for(int j = 0; j < finalSigCurPicInfo.first[i].size();j++)
        {
            qDebug() << finalSigCurPicInfo.first[i][j];
        }
        qDebug() << "标签是:" << finalSigCurPicInfo.second[i].first<< ": "<< \
            finalSigCurPicInfo.second[i].second;
    }
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      removeTheLastSinglePoints
*
*   Discriptions:       移除上一个点
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::removeTheLastSinglePoints()
{
    if(tempPointsList.size() != 0)
    {
        tempPointsList.pop_back();
        ticks--;
        qDebug() << "已经撤销了单个点了";
    }
    update();
    return;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      removeTheLastPolyAndLabel
*
*   Discriptions:       移除上一个轮廓
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void curPicForLabeling_MainWindow::removeTheLastPolyAndLabel()
{
    if(finalSigCurPicInfo.first.size()!= 0)
    {
        /*撤除保存数据*/
        finalSigCurPicInfo.first.pop_back();
        finalSigCurPicInfo.second.pop_back();
        /*撤出绘画的点*/
        curPicPoly.pop_back();
        qDebug() << "已撤销";
    }
    update();
    return;
}

/**************************************************************************************************
*
*   funtions type :     adjust params in class
*
*   work in where :     curPicForLabeling_MainWindow
*
*   Function Name:      writingMethod
*
*   Discriptions:       标签写方法————哥们开摆了自己修改源码
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
QString curPicForLabeling_MainWindow::writingMethod()
{
    QString resultToText;

    for(int i = 0; i < finalSigCurPicInfo.first.size();i++)
    {
        resultToText += LABLE_TEXT_INDEX_PREFIX + QString::number(finalSigCurPicInfo.second[i].first) + \
                        LABLE_TEXT_INSERT_SLASH + LABLE_TEXT_LABLENAME_PREFIX + finalSigCurPicInfo.second[i].second + LABLE_TEXT_INSERT_SLASH;
        QString pointsSetShow = LABLE_TEXT_POINTSET_SHOW_PREFIX + LABLE_TEXT_INSERT_SLASH ;
        for(int j = 0 ; j < finalSigCurPicInfo.first[i].size(); j++)
        {
            pointsSetShow += LABLE_TEXT_POINT_SHOW_PREFIX + QString::number(finalSigCurPicInfo.first[i][j].x())\
                             + LABLE_TEXT_POINT_SPLIT + QString::number(finalSigCurPicInfo.first[i][j].y()) +LABLE_TEXT_POINT_SHOW_SUFFIX+ LABLE_TEXT_INSERT_SLASH;
        }
        pointsSetShow += LABLE_TEXT_POINTSET_END_SHOW + LABLE_TEXT_INSERT_SLASH ;
        resultToText += pointsSetShow;
    }

    return resultToText;
}



>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
