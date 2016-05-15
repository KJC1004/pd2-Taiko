#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    qsrand(QTime::currentTime().second());
    ui->setupUi(this);
    setWindowTitle("Result");
    scene = new QGraphicsScene();
    scene->setSceneRect(10,10,490,490);
    ui->graphicsView->setScene(scene);
    endSound = new QSound(":/sound/sound/smb_mariodie.wav");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::gameEnd(int score){
    endSound->play();
    int type = (score<100? 0: (score<200? 2: 4)) + qrand()%2;
    QImage bg(":/image/image/troll"+QString::number(type)+".jpg");
    scene->setBackgroundBrush(bg.scaled(510,510,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->label->setText("SCORE  :  " + QString::number(score));
    show();
}

void Dialog::on_pushButton_exit_clicked()
{
    emit quit();
}

void Dialog::on_pushButton_retry_clicked()
{
    endSound->stop();
    close();
    emit retry();
}
