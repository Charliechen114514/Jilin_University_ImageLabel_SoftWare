#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    preLoad();

    initMainWindow();

    initDefaultPictures();

    initBasicQuickShot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::preLoad()
{
    QFile loader(DEF_CONFFILE_PATH);
    QStringList def_conf;
    if(loader.open(QIODevice::ReadOnly))
    {

        while(loader.atEnd() == false)
        {
            def_conf.push_back(QString(loader.readLine().toStdString().c_str()));
        }
    }
    else
    {
        QMessageBox::critical(this,"Error occured!", "找不到conf文件,无法保存配置！");
        return;
    }
    // debug node
    for(int i = 0; i < def_conf.size();i++)
    {
        qDebug() << def_conf[i];
    }

    this->defLoadImagePath = def_conf[0].remove("\r\n");
    this->defLoadLabelPath = def_conf[1].remove("\r\n");
    this->defAutoLabelSavePath = def_conf[2].remove("\r\n");
}

/**************************************************************************************************
*
*   funtions type :     basic_init
*
*   work in where :     MainWindow
*
*   Function Name:      initMainWindow
*
*   Discriptions:       This function are used in connecting and trigger others initialization
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::initMainWindow(){

    curViewPicIndex = 0;
    getNewLabelDialog = NULL;
    isIgnoreFailed = true;
    helpWindows = new helpAndCheck(this);
    setSeperatorWindows = new SetSeperatorMainWindow;
    autoLabelWnd = nullptr;
    autoLabelVideoWnd = nullptr;
    defLabelsSeperator = ";";
    setSeperatorWindows->getSeperatorFromMainWindow(defLabelsSeperator);
    curLabelsSeperator = ";";
    /*完成主要链接*/
    /*链接新添加单张图片*/
    connect(ui->action_newPicture,&QAction::triggered,this,&MainWindow::getPictureFromUsr);
    /*链接新添加文件夹*/
    connect(ui->action_newDirectory,&QAction::triggered,this,&MainWindow::getDirectoryFromUsr);
    /*链接删除当前图片*/
    connect(ui->actionremoveSinglePicture,&QAction::triggered,this,&MainWindow::on_removeCurPictureBtn_clicked);
    /*链接删除所有的图片*/
    connect(ui->actionremoveAllPictures,&QAction::triggered,this,&MainWindow::removeAllPictures);
    /*链接替换图片*/
    connect(ui->actionswitchCurPicture,&QAction::triggered,this,&MainWindow::on_changeCurPicBtn_clicked);
    /*链接替换文件夹*/
    connect(ui->actionswitchCurDir,&QAction::triggered,this,&MainWindow::switchPicDir);

    connect(ui->actionaddNewLabel,&QAction::triggered,this,&MainWindow::on_manageLabelButton_clicked);

    connect(ui->actiondeleteOldLabel,&QAction::triggered,this,&MainWindow::on_manageLabelButton_clicked);

    connect(ui->checkQuickKeySequence,&QAction::triggered,helpWindows,&helpAndCheck::show);

    connect(ui->actioncheckAuthor,&QAction::triggered,this,&MainWindow::viewWhoMakeIt);

    connect(ui->actionfindShitBugAndsakForMail,&QAction::triggered,this,&MainWindow::findShitsAndTellAuthors);

    connect(ui->actionimportlabelIndex,&QAction::triggered,this,&MainWindow::importLabelsFromUsr);

    connect(ui->actionSetLabelSeperator,&QAction::triggered,this,&MainWindow::showSetSeperatorMainWindow);

    connect(ui->action_setAutoLabelPath,&QAction::triggered,this,&MainWindow::setAutoLabelSavePath);

    connect(ui->btn_autoLabelVideo,&QPushButton::clicked,this,&MainWindow::on_btn_autoLabelVideo_clicked);
}
/**************************************************************************************************
*   funtions type :     basic_init
*
*   work in where :     MainWindow
*
*   Function Name:      initDefaultPictures
*
*   Discriptions:       This function are used in initing the def_pictures, if we failed to load the pictures
*                       we would turn to init a white pixalMap.
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::initDefaultPictures()
{
    // load pics
    if(!defLoadImagePath.isEmpty())
    {
        QDir getDir(defLoadImagePath);
        // qDebug() << getDirPath;
        if(!getDir.exists()){
            QMessageBox::critical(this, "打开文件夹失败！:(","没有办法打开文件夹...查看一下文件夹姓名是不是有问题");
            USR_INVALID_DFT_REACT;
        }

        getDir.setFilter(QDir::Files|QDir::Hidden|QDir::NoSymLinks);
        getDir.setSorting(QDir::Size|QDir::Reversed);
        /*文件地址链表*/
        QStringList getTargetAllFile;

        getDir.setNameFilters(QString("*.jpg;*.png;*.bmp").split(";"));

        getTargetAllFile = getDir.entryList();

        if(getTargetAllFile.empty()){
            QMessageBox::information(this,"文件夹是空的!","文件夹是空的!或者说并未有识别到目标文件！");
            USR_CANCEL_DFT_REACT;
        }

        QStringList FilePathAll;
        for(int i = 0; i < getTargetAllFile.size();i++){
            QString curPath = defLoadImagePath + "/" +getTargetAllFile[i];
            FilePathAll.push_back(curPath);
            qDebug() << "Have locate the file successfully of the :" << i <<" - " << curPath;
        }
        if(!isIgnoreFailed)
        {
            for(int i = 0; i < FilePathAll.size(); i++)
            {
                curViewPic.load(FilePathAll[i]);
                if(curViewPic.isNull())
                {
                    if(isIgnoreFailed)
                    {
                        FilePathAll.removeAt(i);
                        i--;
                    }
                    else
                    {
                        if(dealFailedInput())
                        {
                            FilePathAll.removeAt(i);
                            i--;
                            continue;
                        }
                        else
                        {
                            FilePathAll.clear();
                        }
                    }
                }

            }
        }
        curViewPic.load(FilePathAll.last());
        pathPics.append(FilePathAll);
        ui->curPlaceProcessBar->setRange(0,pathPics.size());
        curViewPicIndex = pathPics.size();
        imgShow(pathPics.size()-1);
    }
    else
    {
        def_png.load(EMPTY_SHOWN_PNG);
        if(def_png.isNull()){
            QMessageBox::information(NULL,"无法加载图片","啊哈！好像加载不了默认的图片呢...");
            def_png.fill(Qt::white);
        }
        ui->viewLabel->setPixmap(QPixmap::fromImage(def_png.scaled(ui->viewLabel->size(),Qt::IgnoreAspectRatio)));
    }

    // load labels
    if(!defLoadLabelPath.isEmpty())
    {
        QFile readLabel(defLoadLabelPath);
        readLabel.open(QIODevice::ReadOnly);
        QStringList labels = QString(readLabel.readAll()).split(curLabelsSeperator);
        if(labels.empty())
        {
            QMessageBox::critical(this,"发生错误","喂！怎么是空的啊！");
        }
        LabelPair temp;
        int curIndex = 0;
        if(labelList.empty())
        {
            curIndex = 1;
        }
        else
        {
            curIndex = labelList.last().first + 1;
        }

        bool duplicateFlag = false;
        for(int i = 0; i < labels.size(); i++)
        {
            qDebug() << labels[i];
            temp.first = curIndex;
            temp.second = labels[i];
            if(temp.second == ""){
                continue;
            }
            for(int j = 0; j < labelList.size();j++)
            {
                if(temp.second == labelList[j].second)
                {
                    duplicateFlag = true;
                    break;
                }
            }
            if(duplicateFlag)
            {
                duplicateFlag = false;
                continue;
            }
            labelList.push_back(temp);
            curIndex++;
        }
        updateCurrentLabelCheckText();
    }

}

void MainWindow::initBasicQuickShot()
{
    /*快捷键：打开图片*/
    QAction* getNewPic = new QAction;
    getNewPic->setShortcut(QKeySequence(tr("Ctrl+O")));
    ui->menubar->addAction(getNewPic);
    connect(getNewPic,&QAction::triggered,this,&MainWindow::getPictureFromUsr);

    /*快捷键：打开文件夹*/
    QAction* getNewDir = new QAction;
    getNewDir->setShortcut(QKeySequence(tr("Ctrl+Shift+D")));
    ui->menubar->addAction(getNewDir);
    connect(getNewDir,&QAction::triggered,this,&MainWindow::getDirectoryFromUsr);

    /*快捷键：上一张下一张*/

    /*上一张 1 ->键*/
    QAction* toPreviousPic = new QAction;
    toPreviousPic->setShortcut(QKeySequence(tr("Left")));
    ui->menubar->addAction(toPreviousPic);
    connect(toPreviousPic,&QAction::triggered,this,&MainWindow::on_gotoPrevious_clicked);

    /*上一张 2 A键*/
    QAction* toPreviousPic2 = new QAction;
    toPreviousPic2->setShortcut(QKeySequence(tr("A")));
    ui->menubar->addAction(toPreviousPic2);
    connect(toPreviousPic2,&QAction::triggered,this,&MainWindow::on_gotoPrevious_clicked);

    /*下一张1 <-键*/
    QAction* toAfterOne1 = new QAction;
    toAfterOne1->setShortcut(QKeySequence(tr("Right")));
    ui->menubar->addAction(toAfterOne1);
    connect(toAfterOne1,&QAction::triggered,this,&MainWindow::on_gotoAfterOne_clicked);

    /*下一张2 D键*/
    QAction* toAfterOne2 = new QAction;
    toAfterOne2->setShortcut(QKeySequence(tr("D")));
    ui->menubar->addAction(toAfterOne2);
    connect(toAfterOne2,&QAction::triggered,this,&MainWindow::on_gotoAfterOne_clicked);

    /*切换图片*/
    QAction* toSwitch = new QAction;
    toSwitch->setShortcut(QKeySequence(tr("Ctrl+Alt+P")));
    ui->menubar->addAction(toSwitch);
    connect(toSwitch,&QAction::triggered,this,&MainWindow::on_changeCurPicBtn_clicked);

    /*切换文件夹*/
    QAction* toSwitchDir = new QAction;
    toSwitchDir->setShortcut(QKeySequence(tr("Ctrl+Alt+D")));
    ui->menubar->addAction(toSwitchDir);
    connect(toSwitchDir,&QAction::triggered,this,&MainWindow::switchPicDir);

    /*删除当前图片*/
    QAction* toDeleteCurPic = new QAction;
    toDeleteCurPic->setShortcut(tr("Ctrl+D"));
    ui->menubar->addAction(toDeleteCurPic);
    connect(toDeleteCurPic,&QAction::triggered,this,&MainWindow::on_removeCurPictureBtn_clicked);

    /*管理标签*/
    QAction* toManageLabels = new QAction;
    toDeleteCurPic->setShortcut(tr("Ctrl+L"));
    ui->menubar->addAction(toManageLabels);
    connect(toManageLabels,&QAction::triggered,this,&MainWindow::on_manageLabelButton_clicked);

    /*导入标签*/
    QAction* toImportLabel = new QAction;
    toImportLabel->setShortcut(tr("Ctrl + I"));
    ui->menubar->addAction(toImportLabel);
    connect(toImportLabel,&QAction::triggered,this,&MainWindow::importLabelsFromUsr);
}

/**************************************************************************************************
*
*   funtions type :     basicFunction
*
*   work in where :     MainWindow
*
*   Function Name:      imgShow
*
*   Discriptions:       this function shows the pixmap and also calls refresh to make the processBar
*                       synchronously follow the viewLabel
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::imgShow(unsigned int visitIndex)
{
    curViewPic.load(pathPics[visitIndex]);
    if(curViewPic.isNull())
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"注意！","无法显示图片！将会更换图片或者删除之，点击确定表示更换"))
        {
            on_changeCurPicBtn_clicked();
        }
        else
        {
            pathPics.removeAt(visitIndex);

        }
    }
    ui->viewLabel->setPixmap(QPixmap::fromImage(curViewPic.scaled(ui->viewLabel->size(),Qt::IgnoreAspectRatio)));
    refreshProcessBar(visitIndex + 1);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    ui->viewLabel->setPixmap(QPixmap::fromImage(curViewPic.scaled(ui->viewLabel->size(),Qt::IgnoreAspectRatio)));
}

/**************************************************************************************************
*
*   funtions type :     getter
*
*   work in where :     MainWindow
*
*   Function Name:      getPictureFromUsr
*
*   Discriptions:       This function gets single pictures by usr's selection on file dialog
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::getPictureFromUsr()
{
    QString getPicFile = QFileDialog::getOpenFileName(NULL,"选择想要打开的图片",DEBUG_PIC_PATH,ALLOWING_PICSIG_TYPE);

    // 首先判定用户不要中途反悔！防止读取空字符串
    if(getPicFile.isEmpty()){
        USR_CANCEL_DFT_REACT;
    }
    QImage curImage;
    curImage.load(getPicFile);
    if(curImage.isNull()){
        QMessageBox::critical(NULL,"出错了","没有办法加载图片...兄弟看看文件路径?");
        USR_INVALID_DFT_REACT;
    }
    pathPics.push_back(getPicFile);
    ui->curPlaceProcessBar->setRange(0,pathPics.size());
    curViewPicIndex = pathPics.size();
    imgShow(pathPics.size()-1);
}

/**************************************************************************************************
*
*   funtions type :     getter<DIR>
*
*   work in where :     MainWindow
*
*   Function Name:      getDirectoryFromUsr
*
*   Discriptions:       This function gets bunches of pictures by usr's selection on file dialog
*
*   parameters :        void
*
*   return :            void
*
*   Cautions:           this functions only allows selecting PNGs, JPGs and BMPs in this version
**************************************************************************************************/

void MainWindow::getDirectoryFromUsr()
{
    QString getDirPath = QFileDialog::getExistingDirectory(this,"选择目录",DEBUG_PIC_PATH);
    // 用户取消，直接跑路
    if(getDirPath.isEmpty()){
        USR_CANCEL_DFT_REACT;
    }
    QDir getDir(getDirPath);
    // qDebug() << getDirPath;
    if(!getDir.exists()){
        QMessageBox::critical(this, "打开文件夹失败！:(","没有办法打开文件夹...查看一下文件夹姓名是不是有问题");
        USR_INVALID_DFT_REACT;
    }
    if(isRefreshedDefImagePath){
        isRefreshedDefImagePath = false;
        defLoadImagePath = getDirPath;
    }

    defLoadImagePath = getDirPath;

    getDir.setFilter(QDir::Files|QDir::Hidden|QDir::NoSymLinks);
    getDir.setSorting(QDir::Size|QDir::Reversed);
    /*文件地址链表*/
    QStringList getTargetAllFile;

    getDir.setNameFilters(QString("*.jpg;*.png;*.bmp").split(";"));

    getTargetAllFile = getDir.entryList();

    if(getTargetAllFile.empty()){
        QMessageBox::information(this,"文件夹是空的!","文件夹是空的!或者说并未有识别到目标文件！");
        USR_CANCEL_DFT_REACT;
    }

    QStringList FilePathAll;
    for(int i = 0; i < getTargetAllFile.size();i++){
        QString curPath = getDirPath + "/" +getTargetAllFile[i];
        FilePathAll.push_back(curPath);
        qDebug() << "Have locate the file successfully of the :" << i <<" - " << curPath;
    }
    if(!isIgnoreFailed)
    {
        for(int i = 0; i < FilePathAll.size(); i++)
        {
            curViewPic.load(FilePathAll[i]);
            if(curViewPic.isNull())
            {
                if(isIgnoreFailed)
                {
                    FilePathAll.removeAt(i);
                    i--;
                }
                else
                {
                    if(dealFailedInput())
                    {
                        FilePathAll.removeAt(i);
                        i--;
                        continue;
                    }
                    else
                    {
                        FilePathAll.clear();
                    }
                }
            }

        }
    }
    curViewPic.load(FilePathAll.last());
    pathPics.append(FilePathAll);
    ui->curPlaceProcessBar->setRange(0,pathPics.size());
    curViewPicIndex = pathPics.size();
    imgShow(pathPics.size()-1);

}

/**************************************************************************************************
*
*   funtions type :     ExceptionDeal
*
*   work in where :     MainWindow
*
*   Function Name:      dealFailedInput
*
*   Discriptions:       异常处理——图片加载爆炸，用户选择处理
*
*   parameters :        void
*
*   return :            void
*
*   Cautions:           NUL
**************************************************************************************************/
bool MainWindow::dealFailedInput()
{
    QMessageBox curBox;
    curBox.setText("无法加载图片！请再三确保您的图片文件路径是合法的！");
    curBox.setWindowTitle("加载失败了！");
    curBox.resize(480,640);
    QPushButton* cancelAllLoadingBehavior = curBox.addButton(tr("好吧，我放弃加载全部!"),QMessageBox::ActionRole);
    QPushButton* cancelCurOneAndContinue = curBox.addButton(tr("前进，不择手段的前进！"),QMessageBox::ActionRole);
    curBox.exec();
    if(curBox.clickedButton() == cancelAllLoadingBehavior){
        QMessageBox::information(this,"你取消了加载所有的图片！","你取消了加载所有的图片！");
        return 1;
    }
    else if(curBox.clickedButton() == cancelCurOneAndContinue)
    {
        QMessageBox::information(this,"好的，继续加载!","好的，继续加载!");
        return 0;
    }
    return 0;
}




/**************************************************************************************************
*
*   funtions type :     adjustments on widgets
*
*   work in where :     MainWindow
*
*   Function Name:      refreshProcessBar
*
*
*   Discriptions:       This function are usrd in connecting and trigger others initialization
*
*   parameters :        1.int curViewIndex : get the cur_supposed_shown_index
*
*   return :            void
**************************************************************************************************/
void MainWindow::refreshProcessBar(int curViewIndex)
{
    //qDebug() << curViewIndex << " one and totally "<<listImage.size() << " and the ratios is "<< static_cast<int>(curViewIndex/listImage.size());
    ui->curPlaceProcessBar->setValue(curViewIndex);
    QString textBar = "当先你在:"+QString::number(curViewIndex) + "/" + QString::number(pathPics.size());
    ui->processTextLine->setText(textBar);
}

/**************************************************************************************************
*
*   funtions type :     adjustments on widgets, slots
*
*   work in where :     MainWindow
*
*   Function Name:      on_gotoAfterOne_clicked
*
*   Discriptions:       when pressing the "下一张" btn, this function works and the connections are
*                       linked in the initMainWindows
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::on_gotoAfterOne_clicked()
{
    if(pathPics.size() == 0){
        QMessageBox::information(this,"Caution!","我不认为你对一个空的玩意点击下一个有什么好的动机...嗯");
        return;
    }
    curViewPicIndex++;
    if(curViewPicIndex > pathPics.size()){
        QMessageBox::information(this,"Caution!","你已经浏览完最后一张图片了，将自动跳转到第一张图片...");
        curViewPicIndex = 1;
    }
    imgShow(curViewPicIndex - 1);
    return;
}

/**************************************************************************************************
*
*   funtions type :     adjustments on widgets, slots
*
*   work in where :     MainWindow
*
*   Function Name:      on_gotoPreviousOne_clicked
*
*   Discriptions:       when pressing the "上一张" btn, this function works and the connections are
*                       linked in the initMainWindows
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::on_gotoPrevious_clicked()
{
    if(pathPics.size() == 0){
        QMessageBox::information(this,"Caution!","我不认为你对一个空的玩意点击上一个有什么好的动机...嗯");
        return;
    }
    curViewPicIndex--;
    if(curViewPicIndex <= 0){
        QMessageBox::information(this,"Caution!","你已经浏览完最前一张图片了，将自动跳转到最后一张图片...");
        curViewPicIndex = pathPics.size();
    }
    imgShow(curViewPicIndex - 1);
    return;
}

/**************************************************************************************************
*
*   funtions type :     remover
*
*   work in where :     MainWindow
*
*   Function Name:      on_removeCurPictureBtn_clicked
*
*   Discriptions:       when pressing the "移除当前图片" btn, this function works and the connections are
*                       linked in the initMainWindows
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::on_removeCurPictureBtn_clicked()
{
    if(curViewPicIndex == pathPics.size()){
        curViewPicIndex--;
        pathPics.removeAt(curViewPicIndex);
        ui->curPlaceProcessBar->setRange(0,pathPics.size());
        refreshProcessBar(curViewPicIndex);
        if(pathPics.size() == 0){
            QMessageBox::information(NULL,"注意","图片列表已经清空了");
            return;
        }
        if(curViewPicIndex >= 1 && curViewPicIndex < pathPics.size())
        {
            imgShow(curViewPicIndex);
        }
        else{
            imgShow(curViewPicIndex - 1);
        }
        return;
    }
    // curViewPicIndex--;
    if(pathPics.size() == 0){
        QMessageBox::critical(NULL,"出错了！","我们一般认为移除空的东西是一种有毛病的行为！");
        USR_INVALID_DFT_REACT;
    }

    pathPics.removeAt(curViewPicIndex);
    ui->curPlaceProcessBar->setRange(0,pathPics.size());
    refreshProcessBar(curViewPicIndex);

    if(pathPics.size() == 0){
        QMessageBox::information(NULL,"注意","图片列表已经清空了");
        return;
    }
    if(curViewPicIndex >= 1 && curViewPicIndex < pathPics.size() - 1)
    {
        imgShow(curViewPicIndex + 1);
    }
    else{
        imgShow(curViewPicIndex - 1);
    }
    return;
}

/**************************************************************************************************
*
*   funtions type :     switcher
*
*   work in where :     MainWindow
*
*   Function Name:      on_changeCurPicBtn_clicked
*
*   Discriptions:       when pressing the "更换当前图片" btn, this function works and the connections are
*                       linked in the initMainWindows
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/

void MainWindow::on_changeCurPicBtn_clicked()
{
    QString getPicFile = QFileDialog::getOpenFileName(NULL,"选择想要打开的图片",DEBUG_PIC_PATH,ALLOWING_PICSIG_TYPE);

    // 首先判定用户不要中途反悔！防止读取空字符串
    if(getPicFile.isEmpty()){
        USR_CANCEL_DFT_REACT;
    }

    curViewPic.load(getPicFile);
    if(curViewPic.isNull()){
        QMessageBox::critical(NULL,"出错了","没有办法加载图片...兄弟看看文件路径?");
        imgShow(curViewPicIndex - 1);
        USR_INVALID_DFT_REACT;
    }
    pathPics.replace(curViewPicIndex-1,getPicFile);

    imgShow(curViewPicIndex - 1);
}

/**************************************************************************************************
*
*   funtions type :     switcher
*
*   work in where :     MainWindow
*
*   Function Name:      switchPicDir
*
*   Discriptions:       when pressing the "更换文件夹" menuSign, this function works and the connections are
*                       linked in the initMainWindows
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::switchPicDir()
{
    if(pathPics.size() == 0){
        QMessageBox::information(NULL,"建议","我觉得，你是不是应该考虑添加文件夹呢?");
        getDirectoryFromUsr();
        return;
    }
    isRefreshedDefImagePath = true;
    removeAllPictures();
    getDirectoryFromUsr();

}

/**************************************************************************************************
*
*   funtions type :     remover
*
*   work in where :     MainWindow
*
*   Function Name:      removeAllPictures
*
*   Discriptions:       when pressing the "移除所有图片" menuSign, this function works and the connections are
*                       linked in the initMainWindows
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::removeAllPictures()
{
    if(pathPics.size() == 0){
        QMessageBox::critical(NULL,"出错了！","我们一般认为移除空的东西是一种有毛病的行为！");
        USR_INVALID_DFT_REACT;
    }

    pathPics.clear();
    ui->curPlaceProcessBar->setRange(0,1);
    refreshProcessBar(0);
    initDefaultPictures();
}

/**************************************************************************************************
*   funtions type :     switchWindow
*
*   work in where :     MainWindow      ->      editPicWindow
*
*   Function Name:      on_removeCurPictureBtn_clicked
*
*   Discriptions:       when pressing the "移除所有图片" menuSign, this function works and the
*                       connections are linked in the initMainWindows
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::on_changeToManuallyLable_clicked()
{
    if(pathPics.empty()){

        QMessageBox::critical(this,"发生错误！","哥们你图片呢？");

        USR_INVALID_DFT_REACT;
    }

    editPicWindow = new manuallyLabel(this);
    editPicWindow->setWindowTitle("标注模式");
    editPicWindow->setSeperator(curLabelsSeperator);
    connect(editPicWindow,&manuallyLabel::refreshMainWindowLabelList,this,&MainWindow::fetchLabelListFromManuallyLabel);
    /*刷新单张手工编辑完成的数据，这是通过接受返回单张图片的信息得到的*/
    connect(editPicWindow,&manuallyLabel::finishWholeEditing_ReturnCurSinglePagePointsAndLabelInfo,this,&MainWindow::fetchFromManuallyLabel);

    editPicWindow->setManuallyWindowPixMapLists(pathPics);
    editPicWindow->setManuallyWindowLabelList(labelList);

    editPicWindow->show();
}

/**************************************************************************************************
*
*   funtions type :     switchWindow
*
*   work in where :     MainWindow      ->      labelQuerydialog
*
*   Function Name:      on_manageLabelButton_clicked
*
*   Discriptions:       管理标签
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::on_manageLabelButton_clicked()
{
    getNewLabelDialog = new labelQuerydialog;
    getNewLabelDialog->setSeperator(curLabelsSeperator);
    /*通过添加标签获得新的标签*/
    connect(getNewLabelDialog,&labelQuerydialog::finishSelectingLabel,this,&MainWindow::updateLabelListForMainWindow);;
    getNewLabelDialog->getTheCurrentLabelList(labelList);
    getNewLabelDialog->initTextLableShow();
    getNewLabelDialog->showcheckedBoxListsSelections();
    getNewLabelDialog->show();
}

/**************************************************************************************************
*
*   funtions type :     getter
*
*   work in where :     MainWindow
*
*   Function Name:      fetchFromManuallyLabel
*
*   Discriptions:       拿回数据（从manuallyLabel Window）（deprecated as save is done while labeling ）
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::fetchFromManuallyLabel()
{
    Pair_Label_Shape getter = editPicWindow->returnSingelPictureLabelsRecord();
    if(getter.first.isEmpty() || getter.second.isEmpty()){
        qDebug() << "检测到取消操作";
        return;
    }
    wholeCoreData.push_back(getter);
}

/**************************************************************************************************
*   funtions type :     getter
*   work in where :     MainWindow
*   Function Name:      fetchLabelListFromManuallyLabel
*   Discriptions:       拿回标签（从manuallyLabel Window）
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::fetchLabelListFromManuallyLabel()
{
    QList<LabelPair> labelListget = editPicWindow->returnUsableLabelPairListToMainWindow();
    if(!labelListget.isEmpty()){
        qDebug() << "不是取消操作";
        labelList = labelListget;
    }
    updateCurrentLabelCheckText();
}

/**************************************************************************************************
*
*   funtions type :     update
*
*   work in where :     MainWindow
*
*   Function Name:      updateLabelListForMainWindow
*
*
*   Discriptions:       从Mannuallabel那里刷新标签
*
*   parameters :        void
*
*   return :            void
*
**************************************************************************************************/
void MainWindow::updateLabelListForMainWindow()
{
    labelList = getNewLabelDialog->reFreshMainWindowsLabelList();
    qDebug() << "接受到" << labelList.size() << "个标签";
    for(int i = 0; i < labelList.size(); i++){
        labelList[i].first = i + 1;
    }
    updateCurrentLabelCheckText();
}

/**************************************************************************************************
*
*   funtions type :     update
*   work in where :     MainWindow
*   Function Name:      updateLabelListForMainWindow
*   Discriptions:       刷新文本标签
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::updateCurrentLabelCheckText()
{
    QString labelTextRes;
    for(int i = 0; i < labelList.size();i++)
    {
        labelTextRes += QString::number(labelList[i].first) +QString(": ") + labelList[i].second + QString("\n");
    }

    ui->currentLabelCheck->setText(labelTextRes);
    update();
}

void MainWindow::viewWhoMakeIt()
{
    QMessageBox::about(this,"啊哈！欢迎！","这是来自吉林大学的Charliechen114514和changshanzhao制作的小小的标注工具!");
}

void MainWindow::findShitsAndTellAuthors()
{
    QMessageBox::information(this,"啊哈！找对地方了","Charliechen的邮箱:chengh1922.jlu.edu.cn\nchangshanzhao的还得等等");
}

/**************************************************************************************************
*
*   funtions type :     getter
*
*   work in where :     MainWindow
*
*   Function Name:      importLabelsFromUsr
*
*   Discriptions:       外部导入标签
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::importLabelsFromUsr()
{
    QString filePath = QFileDialog::getOpenFileName(this,"选择准备导入的已有的标签文件",".","txt文件(.txt)");
    if(filePath.isEmpty())
    {
        return;
    }
    qDebug() << filePath;
    QFile readLabel(filePath);
    readLabel.open(QIODevice::ReadOnly);
    QStringList labels = QString(readLabel.readAll()).split(curLabelsSeperator);
    if(labels.empty())
    {
        QMessageBox::critical(this,"发生错误","喂！怎么是空的啊！");
    }
    LabelPair temp;
    int curIndex = 0;
    if(labelList.empty())
    {
        curIndex = 1;
    }
    else
    {
        curIndex = labelList.last().first + 1;
    }

    bool duplicateFlag = false;
    for(int i = 0; i < labels.size(); i++)
    {
        qDebug() << labels[i];
        temp.first = curIndex;
        temp.second = labels[i];
        if(temp.second == ""){
            continue;
        }
        for(int j = 0; j < labelList.size();j++)
        {
            if(temp.second == labelList[j].second)
            {
                duplicateFlag = true;
                break;
            }
        }
        if(duplicateFlag)
        {
            duplicateFlag = false;
            continue;
        }
        labelList.push_back(temp);
        curIndex++;
    }
    updateCurrentLabelCheckText();
    return;
}

/**************************************************************************************************
*
*   funtions type :     setter
*
*   work in where :     MainWindow
*
*   Function Name:      showSetSeperatorMainWindow
*
*   Discriptions:       显示分割符窗口
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::showSetSeperatorMainWindow()
{
    connect(setSeperatorWindows,&SetSeperatorMainWindow::finishEditAndReadyReturn,this,&MainWindow::getSetSeperatorFromSSMW);
    setSeperatorWindows->getSeperatorFromMainWindow(curLabelsSeperator);
    setSeperatorWindows->show();
}

/**************************************************************************************************
*
*   funtions type :     getter
*
*   work in where :     MainWindow
*
*   Function Name:      getSetSeperatorFromSSMW(SSMW: SetSeperatorMainWindow)
*
*   Discriptions:       设置导入分割符
*
*   parameters :        void
*
*   return :            void
**************************************************************************************************/
void MainWindow::getSetSeperatorFromSSMW()
{
    curLabelsSeperator = setSeperatorWindows->returnOutFinalSeperator();
}

void MainWindow::on_btn_autoLabel_clicked()
{
    if(autoLabelWnd != nullptr)
    {
        delete autoLabelWnd;
    }

    if(pathPics.empty())
    {
        QMessageBox::critical(this,"KAO","哥们没有图片！");
        return;
    }
    if(labelList.empty())
    {
        QMessageBox::critical(this,"KAO","哥们没有标签！");
        return;
    }
    autoLabelWnd = new AutoLabelWindow(this);
    autoLabelWnd->setMouseTracking(true);
    autoLabelWnd->setLabelLists(labelList);
    autoLabelWnd->setPicturePaths(pathPics);
    autoLabelWnd->setResSavePath(defAutoLabelSavePath);
    autoLabelWnd->show();
}

void MainWindow::setAutoLabelSavePath()
{
    QString savePath = QFileDialog::getExistingDirectory(this,"设置保存路径",".");

    if(savePath.isEmpty()){
        return;
    }

    defAutoLabelSavePath = savePath;
    qDebug() << defAutoLabelSavePath;
}





void MainWindow::closeEvent(QCloseEvent* env[[maybe_unused]])
{
    QFile loader(DEF_CONFFILE_PATH);
    QStringList def_conf;
    def_conf.push_back(defLoadImagePath);
    def_conf.push_back(defLoadLabelPath);
    def_conf.push_back(defAutoLabelSavePath);

    if(loader.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream out(&loader);
        for(int i = 0; i < def_conf.size();i++){
            out << def_conf[i] << "\n";
        }
    }
    else{
        QMessageBox::critical(this,"Load Failed","没有找到conf文件,下次默认配置加载可能会产生失败！");
    }
}

void MainWindow::on_btn_autoLabelVideo_clicked()
{
    // experimental section, re-compile this if you wanna try!

//    if(autoLabelVideoWnd != nullptr){
//        delete autoLabelVideoWnd;
//    }

//    autoLabelVideoWnd = new AutoLabelVideoWindow(this);
//    autoLabelVideoWnd->initVideo("../JLU_Image_TransAnd_Label/videoSample/test3.mp4");
//    autoLabelVideoWnd->show();
}

