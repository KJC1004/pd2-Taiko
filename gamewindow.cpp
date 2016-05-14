#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    setWindowTitle("GameWindow");

    QImage bg(":/image/image/bg.png");
    scene = new Scene();
    scene->setSceneRect(10,10,1190,890);
    scene->setBackgroundBrush(bg.scaled(1210,910,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->graphicsView->setScene(scene);

    QObject::connect(this, SIGNAL(gameStart()), scene, SLOT(gameStart()));
    QObject::connect(scene, SIGNAL(gameEnd(int)), this, SIGNAL(gameEnd(int)));
    QObject::connect(scene, SIGNAL(sendScore(int,int)), this, SLOT(receiveScore(int,int)));
    QObject::connect(scene, SIGNAL(sendTime(int)), this, SLOT(receiveTime(int)));
    QObject::connect(scene, SIGNAL(quit()), this, SIGNAL(quit()));
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::receiveTime(int time){
    ui->label_time->setText("Time  :  " + QString::number(time));
}

void GameWindow::receiveScore(int score, int combo){
    ui->label_score->setText("Score  :  " + QString::number(score));
    ui->label_combo->setText("Combo  " + QString::number(combo));
}
