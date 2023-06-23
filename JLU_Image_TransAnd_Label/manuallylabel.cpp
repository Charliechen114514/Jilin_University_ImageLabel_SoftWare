#include "manuallylabel.h"
#include "ui_manuallylabel.h"
#define UNSAVE  0
#define SAVE    1

#define DEF_PEN_COLOR QColor(0,0,255)
#define DEF_PEN_CURDRAW_COLOR QColor(255,0,0)
#define DEF_PRN_WIDTH 3

manuallyLabel::manuallyLabel(QString curViewPath,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manuallyLabel)
{
    setMouseTracking(true);
    QImage tmp;
    tmp.load(curViewPath);
    showWindow = new setPenWidthWindows;
    ui->setupUi(this);
    isSave = UNSAVE;
    ui->editPicLable->initPixelMap(curViewPath);
    ui->editPicLable->setPixmap(QPixmap::fromImage(tmp.scaled(ui->editPicLable->size(),Qt::IgnoreAspectRatio)));
    ui->editPicLable->initUsrPen();
    initTabTextBox();
    connect(showWindow,&setPenWidthWindows::finishedEdit,this,&manuallyLabel::getEditedChangedWidth);
}


void manuallyLabel::initTabTextBox()
{
    QString colorTextSet = "当前的颜色是: RGB(";
    colorTextSet += QString::number(
        *helper_getColorRGBs((ui->editPicLable->getUsrPenInfo().color()))
        );

    colorTextSet += ",";
    colorTextSet += QString::number(
        *(helper_getColorRGBs((ui->editPicLable->getUsrPenInfo().color())) + 1)
        );
    colorTextSet += ",";
    colorTextSet += QString::number(
        *(helper_getColorRGBs((ui->editPicLable->getUsrPenInfo().color())) + 2)
        );

    colorTextSet += ")";
    qDebug() << colorTextSet;
    ui->showCurColorTextBrowser->setText(colorTextSet);
}


manuallyLabel::~manuallyLabel()
{
    delete ui;
}


void manuallyLabel::on_changeColorBtn_clicked()
{
    ui->editPicLable->getInterFaceQPen().setColor(QColorDialog::getColor());
}

void manuallyLabel::on_changeWidthBtn_clicked()
{
    showWindow->show();

}
void manuallyLabel::getEditedChangedWidth()
{
    unsigned int newWidth = showWindow->getFinalSetPenWidth();
    ui->editPicLable->getInterFaceQPen().setWidth(newWidth);
}
