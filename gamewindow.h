#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>
#include "scene.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

signals:
    void gameStart();
    void gameEnd(int);
    void quit();

private slots:
    void receiveTime(int);
    void receiveScore(int,int);

private:
    Ui::GameWindow *ui;
    Scene *scene;
};

#endif // GAMEWINDOW_H
