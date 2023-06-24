#include "mainwindow.h"
#include "ui_mainwindow.h"

#define USR_CANCEL_DFT_REACT return
#define USR_INVALID_DFT_REACT return
#define DEBUG_PIC_PATH "../JLU_Image_TransAnd_Label/"
#define ALLOWING_PICDIR_TYPE QString("*.jpg;*.png;*.bmp").split(";")
#define ALLOWING_PICSIG_TYPE "PNG 图片(*.png);;JPG 图片(*.jpg);;BMP图片(*.bmp)"
#define EMPTY_SHOWN_PNG "../JLU_Image_TransAnd_Label/default_png/def_png.png"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initMainWindow();

    initDefaultPictures();

    initBasicQuickShot();
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**************************************************************************************************
*   funtions type :     basic_init
*   work in where :     MainWindow
*   Function Name:      initMainWindow
*   Discriptions:       This function are used in connecting and trigger others initialization
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::initMainWindow(){

    curViewPicIndex = 0;
    getNewLabelDialog = NULL;
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



}
/**************************************************************************************************
*   funtions type :     basic_init
*   work in where :     MainWindow
*   Function Name:      initDefaultPictures
*   Discriptions:       This function are used in initing the def_pictures, if we failed to load the pictures
*                       we would turn to init a white pixalMap.
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::initDefaultPictures()
{
    def_png.load(EMPTY_SHOWN_PNG);
    if(def_png.isNull()){
        QMessageBox::information(NULL,"无法加载图片","啊哈！好像加载不了默认的图片呢...");
        def_png.fill(Qt::white);
    }

    ui->viewLabel->setPixmap(QPixmap::fromImage(def_png.scaled(ui->viewLabel->size(),Qt::IgnoreAspectRatio)));
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
    toSwitch->setShortcut(QKeySequence(tr("Ctrl+Shift+S")));
    ui->menubar->addAction(toSwitch);
    connect(toSwitch,&QAction::triggered,this,&MainWindow::on_changeCurPicBtn_clicked);

    /*删除当前图片*/
    QAction* toDeleteCurPic = new QAction;
    toDeleteCurPic->setShortcut(tr("Ctrl+D"));
    ui->menubar->addAction(toDeleteCurPic);
    connect(toDeleteCurPic,&QAction::triggered,this,&MainWindow::on_removeCurPictureBtn_clicked);

}

/**************************************************************************************************
*   funtions type :     basicFunction
*   work in where :     MainWindow
*   Function Name:      imgShow
*   Discriptions:       this function shows the pixmap and also calls refresh to make the processBar
*                       synchronously follow the viewLabel
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::imgShow(unsigned int visitIndex)
{
    QImage curShow = listImage[visitIndex];
    ui->viewLabel->setPixmap(QPixmap::fromImage(curShow.scaled(ui->viewLabel->size(),Qt::IgnoreAspectRatio)));
    refreshProcessBar(visitIndex + 1);
}
/**************************************************************************************************
*   funtions type :     getter
*   work in where :     MainWindow
*   Function Name:      getPictureFromUsr
*   Discriptions:       This function gets single pictures by usr's selection on file dialog
*   parameters :        void
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
    listImage.push_back(curImage);
    pathPics.push_back(getPicFile);
    ui->curPlaceProcessBar->setRange(0,listImage.size());
    curViewPicIndex = listImage.size();
    imgShow(listImage.size()-1);
}

/**************************************************************************************************
*   funtions type :     getter<DIR>
*   work in where :     MainWindow
*   Function Name:      getDirectoryFromUsr
*   Discriptions:       This function gets bunches of pictures by usr's selection on file dialog
*   parameters :        void
*   return :            void
*   Cautions:           this functions only allows selecting PNGs, JPGs and BMPs in this version
**************************************************************************************************/

void MainWindow::getDirectoryFromUsr()
{
    QString getDirPath = QFileDialog::getExistingDirectory(this,"选择目录",DEBUG_PIC_PATH);
    if(getDirPath.isEmpty()){
        USR_CANCEL_DFT_REACT;
    }
    QDir getDir(getDirPath);
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
        QString curPath = getDirPath + "/" +getTargetAllFile[i];
        FilePathAll.push_back(curPath);
        qDebug() << "Have locate the file successfully of the :" << i <<" - " << curPath;
    }

    for(int i = 0; i < FilePathAll.size(); i++)
    {
        QMessageBox curBox;
        curBox.setText("无法加载图片！请再三确保您的图片文件路径是合法的！");
        curBox.setWindowTitle("加载失败了！");
        curBox.resize(480,640);
        QPushButton* cancelAllLoadingBehavior = curBox.addButton(tr("好吧，我放弃加载全部!"),QMessageBox::ActionRole);
        QPushButton* cancelCurOneAndContinue = curBox.addButton(tr("前进，不择手段的前进！"),QMessageBox::ActionRole);
        QImage currentImg;
        currentImg.load(FilePathAll[i]);
        if(currentImg.isNull())
        {
            curBox.exec();
            if(curBox.clickedButton() == cancelAllLoadingBehavior){
                QMessageBox::information(this,"你取消了加载所有的图片！","你取消了加载所有的图片！");
                USR_CANCEL_DFT_REACT;
            }
            else if(curBox.clickedButton() == cancelCurOneAndContinue){
                QMessageBox::information(this,"好的，继续加载!","好的，继续加载!");
                continue;
            }
        }

        listImage.push_back(currentImg);
        pathPics.push_back(FilePathAll[i]);
    }

    ui->curPlaceProcessBar->setRange(0,listImage.size());
    curViewPicIndex = listImage.size();
    imgShow(listImage.size()-1);

}

/**************************************************************************************************
*   funtions type :     adjustments on widgets
*   work in where :     MainWindow
*   Function Name:      refreshProcessBar
*   Discriptions:       This function are usrd in connecting and trigger others initialization
*   parameters :        1.int curViewIndex : get the cur_supposed_shown_index
*   return :            void
**************************************************************************************************/
void MainWindow::refreshProcessBar(int curViewIndex)
{
    //qDebug() << curViewIndex << " one and totally "<<listImage.size() << " and the ratios is "<< static_cast<int>(curViewIndex/listImage.size());
    ui->curPlaceProcessBar->setValue(curViewIndex);
    QString textBar = "当先你在:"+QString::number(curViewIndex) + "/" + QString::number(listImage.size());
    ui->processTextLine->setText(textBar);
}

/**************************************************************************************************
*   funtions type :     adjustments on widgets, slots
*   work in where :     MainWindow
*   Function Name:      on_gotoAfterOne_clicked
*   Discriptions:       when pressing the "下一张" btn, this function works and the connections are
*                       linked in the initMainWindows
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::on_gotoAfterOne_clicked()
{
    if(listImage.size() == 0){
        QMessageBox::information(this,"Caution!","我不认为你对一个空的玩意点击下一个有什么好的动机...嗯");
        return;
    }
    curViewPicIndex++;
    if(curViewPicIndex > listImage.size()){
        QMessageBox::information(this,"Caution!","你已经浏览完最后一张图片了，将自动跳转到第一张图片...");
        curViewPicIndex = 1;
    }
    imgShow(curViewPicIndex - 1);
    return;
}

/**************************************************************************************************
*   funtions type :     adjustments on widgets, slots
*   work in where :     MainWindow
*   Function Name:      on_gotoPreviousOne_clicked
*   Discriptions:       when pressing the "上一张" btn, this function works and the connections are
*                       linked in the initMainWindows
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::on_gotoPrevious_clicked()
{
    if(listImage.size() == 0){
        QMessageBox::information(this,"Caution!","我不认为你对一个空的玩意点击上一个有什么好的动机...嗯");
        return;
    }
    curViewPicIndex--;
    if(curViewPicIndex <= 0){
        QMessageBox::information(this,"Caution!","你已经浏览完最前一张图片了，将自动跳转到最后一张图片...");
        curViewPicIndex = listImage.size();
    }
    imgShow(curViewPicIndex - 1);
    return;
}

/**************************************************************************************************
*   funtions type :     remover
*   work in where :     MainWindow
*   Function Name:      on_removeCurPictureBtn_clicked
*   Discriptions:       when pressing the "移除当前图片" btn, this function works and the connections are
*                       linked in the initMainWindows
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::on_removeCurPictureBtn_clicked()
{
    curViewPicIndex--;
    if(listImage.size() == 0){
        QMessageBox::critical(NULL,"出错了！","我们一般认为移除空的东西是一种有毛病的行为！");
        USR_INVALID_DFT_REACT;
    }

    listImage.removeAt(curViewPicIndex);
    ui->curPlaceProcessBar->setRange(0,listImage.size());
    refreshProcessBar(curViewPicIndex);

    if(listImage.size() == 0){
        QMessageBox::information(NULL,"注意","图片列表已经清空了");
        return;
    }
    imgShow(curViewPicIndex - 1);
    return;
}

/**************************************************************************************************
*   funtions type :     switcher
*   work in where :     MainWindow
*   Function Name:      on_changeCurPicBtn_clicked
*   Discriptions:       when pressing the "更换当前图片" btn, this function works and the connections are
*                       linked in the initMainWindows
*   parameters :        void
*   return :            void
**************************************************************************************************/

void MainWindow::on_changeCurPicBtn_clicked()
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
    listImage.replace(curViewPicIndex-1,curImage);

    imgShow(curViewPicIndex - 1);
}

/**************************************************************************************************
*   funtions type :     switcher
*   work in where :     MainWindow
*   Function Name:      switchPicDir
*   Discriptions:       when pressing the "更换文件夹" menuSign, this function works and the connections are
*                       linked in the initMainWindows
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::switchPicDir()
{
    if(listImage.size() == 0){
        QMessageBox::information(NULL,"建议","我觉得，你是不是应该考虑添加文件夹呢?");
        getDirectoryFromUsr();
        return;
    }

    removeAllPictures();
    getDirectoryFromUsr();
}

/**************************************************************************************************
*   funtions type :     remover
*   work in where :     MainWindow
*   Function Name:      removeAllPictures
*   Discriptions:       when pressing the "移除所有图片" menuSign, this function works and the connections are
*                       linked in the initMainWindows
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::removeAllPictures()
{
    if(listImage.size() == 0){
        QMessageBox::critical(NULL,"出错了！","我们一般认为移除空的东西是一种有毛病的行为！");
        USR_INVALID_DFT_REACT;
    }

    listImage.clear();
    ui->curPlaceProcessBar->setRange(0,1);
    refreshProcessBar(0);
    initDefaultPictures();
}

/**************************************************************************************************
*   funtions type :     switchWindow
*   work in where :     MainWindow      ->      editPicWindow
*   Function Name:      on_removeCurPictureBtn_clicked
*   Discriptions:       when pressing the "移除所有图片" menuSign, this function works and the
*                       connections are linked in the initMainWindows
*   parameters :        void
*   return :            void
**************************************************************************************************/
void MainWindow::on_changeToManuallyLable_clicked()
{
    if(pathPics.empty()){

        QMessageBox::critical(this,"发生错误！","哥们你图片呢？");

        USR_INVALID_DFT_REACT;
    }

    editPicWindow = new manuallyLabel(pathPics[curViewPicIndex-1]);
    editPicWindow->setWindowTitle("标注模式");
    connect(editPicWindow,&manuallyLabel::refreshMainWindowLabelList,this,&MainWindow::fetchLabelListFromManuallyLabel);
    /*刷新单张手工编辑完成的数据，这是通过接受返回单张图片的信息得到的*/
    connect(editPicWindow,&manuallyLabel::finishWholeEditing_ReturnCurSinglePagePointsAndLabelInfo,this,&MainWindow::fetchFromManuallyLabel);

    editPicWindow->setManuallyWindowLabelList(labelList);
    editPicWindow->show();
}


void MainWindow::on_addNewLebelButton_clicked()
{
    getNewLabelDialog = new labelQuerydialog;
    /*通过添加标签获得新的标签*/
    connect(getNewLabelDialog,&labelQuerydialog::finishSelectingLabel,this,&MainWindow::updateLabelListForMainWindow);;
    getNewLabelDialog->getTheCurrentLabelList(labelList);
    getNewLabelDialog->initTextLableShow();
    getNewLabelDialog->showcheckedBoxListsSelections();
    getNewLabelDialog->setTheFistIndex(0);
    getNewLabelDialog->show();
}

void MainWindow::fetchFromManuallyLabel()
{
    Pair_Label_Shape getter = editPicWindow->returnSingelPictureLabelsRecord();
    if(getter.first.isEmpty() || getter.second.isEmpty()){
        qDebug() << "检测到取消操作";
        return;
    }
    wholeCoreData.push_back(getter);
}

void MainWindow::fetchLabelListFromManuallyLabel()
{
    QList<LabelPair> labelListget = editPicWindow->returnUsableLabelPairListToMainWindow();
    if(!labelListget.isEmpty()){
        qDebug() << "不是取消操作";
        labelList = labelListget;
    }
    updateCurrentLabelCheckText();
    getNewLabelDialog ->getTheCurrentLabelList(labelList);
}

void MainWindow::updateLabelListForMainWindow()
{
    labelList = getNewLabelDialog->reFreshMainWindowsLabelList();
    for(int i = 0; i < labelList.size(); i++){
        labelList[i].first = i + 1;
    }
    updateCurrentLabelCheckText();
}

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
