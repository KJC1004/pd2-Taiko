#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QLabel>
#include <QSound>
#include <QTime>
#include <QTimer>
#include "drum.h"

class Scene: public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();

protected:
    void keyPressEvent(QKeyEvent *);

signals:
    void sendTime(int);
    void sendScore(int,int);
    void gameEnd(int);
    void clearDrum();
    void quit();

private slots:
    void setTime();
    void gameStart();
    void gamePause();
    void spawnDrum();
    void check();

private:
    void hitDrum(int);
    void end();
    int gcd(int,int);

    QTimer *tmr_time, *tmr_move, *tmr_spawn, *tmr_fps;
    QGraphicsPixmapItem hitSign, ref[4];
    QPixmap drumType[4], explosion[2][2][17], transparent;
    QSound *drumSound[4], *startSound, *failSound, *pauseSound;
    QList<Drum *> drum;
    Drum *spawn;

    const int hitX=200, spawnX=1200, Y=350, S=150;
    const int timeps=1, moveps=60, spawnps=3, fps=30;
    bool paused = false;
    int time, score, combo;
    int drumTypeS, explosionS;
    double ratio;
};

#endif // SCENE_H
