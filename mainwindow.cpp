#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("StartWindow");

    QImage bg(":/image/image/start1.jpg");
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(10,10,1190,890);
    scene->setBackgroundBrush(bg.scaled(1210, 910, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    bgm = new QSound(":/sound/sound/smb_stage_clear.wav");
    bgm->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_S: on_pushButton_start_clicked(); break;
        case Qt::Key_Home: on_pushButton_exit_clicked(); break;
        default: break;
    }
}

void MainWindow::on_pushButton_start_clicked()
{
    bgm->stop();
    close();
    emit gwshow();
}

void MainWindow::on_pushButton_exit_clicked()
{
    emit quit();
}
