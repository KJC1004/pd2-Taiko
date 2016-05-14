#include "scene.h"

Scene::Scene()
{
    qsrand(QTime::currentTime().second());
    int s;

    QPixmap notes(":/image/image/notes.png");
    s = gcd(notes.width(), notes.height());
    for(int i=0; i<4; i++){
        drumType[i] = notes.copy(QRect((i+1)*s,0,s,s)).scaled(S,S);
        ref[i].setPixmap(drumType[i].scaled(200,200));
        ref[i].setPos(80+280*i,600);
        addItem(&ref[i]);
    }
    hitSign.setPixmap(notes.copy(QRect(0,0,s,s)).scaled(S,S));
    hitSign.setPos(hitX,Y-hitSign.pixmap().height()/2);
    addItem(&hitSign);

    QPixmap explode(":/image/image/explosion_lower.png");
    s = gcd(explode.width(), explode.height());
    ratio = (double)s/gcd(notes.width(),notes.height());
    for(int i=0; i<4; i++)
        for(int j=0; j<17; j++)
            explosion[i/2][i%2][j] = explode.copy(QRect(j*s,i*s,s,s)).scaled(S*ratio,S*ratio);
    transparent = explosion[0][0][16];

    drumSound[0] = new QSound(":/sound/sound/smb_jump-small.wav");
    drumSound[1] = new QSound(":/sound/sound/smb_stomp.wav");
    drumSound[2] = new QSound(":/sound/sound/smb_jump-super.wav");
    drumSound[3] = new QSound(":/sound/sound/smb_kick.wav");
    startSound = new QSound(":/sound/sound/smb_powerup.wav");
    failSound = new QSound(":/sound/sound/smb_bump.wav");
    pauseSound = new QSound(":/sound/sound/smb_pause.wav");
}

void Scene::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_S: hitDrum(0); break;
        case Qt::Key_K: hitDrum(1); break;
        case Qt::Key_A: hitDrum(2); break;
        case Qt::Key_L: hitDrum(3); break;
        case Qt::Key_P: gamePause(); break;
        case Qt::Key_Insert: emit sendTime(time+=5); break;
        case Qt::Key_Delete: emit sendTime(time-=5); break;
        case Qt::Key_End: end(); break;
        case Qt::Key_Home: emit quit(); break;
        default: break;
    }
}

void Scene::setTime(){
    emit sendTime(time--);
    if(time<0) end();
}

void Scene::gameStart(){
    startSound->play();

    time = 30;
    score = 0;
    combo = 0;
    emit sendTime(time--);
    emit sendScore(score,combo);

    tmr_time = new QTimer();
    tmr_time->start(1000/timeps);
    QObject::connect(tmr_time, SIGNAL(timeout()), this, SLOT(setTime()));

    tmr_move = new QTimer();
    tmr_move->start(1000/moveps);
    QObject::connect(tmr_move, SIGNAL(timeout()), this, SLOT(check()));

    tmr_spawn = new QTimer();
    tmr_spawn->start(1000/spawnps);
    QObject::connect(tmr_spawn, SIGNAL(timeout()), this, SLOT(spawnDrum()));

    tmr_fps = new QTimer();
    tmr_fps->start(1000/fps);
}

void Scene::gamePause(){
    pauseSound->play();
    if(paused){
        tmr_time->start();
        tmr_move->start();
        tmr_spawn->start();
        tmr_fps->start();
    }else{
        tmr_time->stop();
        tmr_move->stop();
        tmr_spawn->stop();
        tmr_fps->stop();
    }
    paused = !paused;
}

void Scene::spawnDrum(){
    if(qrand()%2<1){
        spawn = new Drum();
        spawn->ID = qrand()%4;
        for(int i=0; i<2; i++)
            for(int j=0; j<17; j++)
                spawn->explosion[i][j] = &explosion[spawn->ID/2][i][j];
        spawn->setPixmap(drumType[spawn->ID]);
        spawn->setPos(spawnX,Y-(spawn->pixmap().height()/2));
        drum.append(spawn);
        addItem(spawn);
        QObject::connect(tmr_move, SIGNAL(timeout()), spawn, SLOT(move()));
        QObject::connect(this, SIGNAL(clearDrum()), spawn, SLOT(deleteLater()));
    }
}

void Scene::check(){
    if(!drum.empty() && drum[0]->x() < hitX-50){
        failSound->play();
        drum[0]->hit = 1;
        drum[0]->setPixmap(transparent);
        drum[0]->moveBy(-S*(ratio-1)/2,-S*(ratio-1)/2);
        QObject::connect(tmr_fps, SIGNAL(timeout()), drum[0], SLOT(animate()));
        drum.removeFirst();
        score--;
        combo = 0;
        emit sendScore(score, combo);
    }
}

void Scene::hitDrum(int ID){
    if(!paused && !drum.empty()){
        if(ID==drum[0]->ID && drum[0]->x() < hitX+50){
            drum[0]->hit = 0;
            drumSound[drum[0]->ID]->play();
            score += combo++;
        }else{
            drum[0]->hit = 1;
            failSound->play();
            score--;
            combo = 0;
        }
        drum[0]->setPixmap(transparent);
        drum[0]->moveBy(-S*(ratio-1)/2,-S*(ratio-1)/2);
        QObject::connect(tmr_fps, SIGNAL(timeout()), drum[0], SLOT(animate()));
        drum.removeFirst();
        emit sendScore(score, combo);
    }
}

void Scene::end(){
    startSound->stop();
    paused = false;
    delete tmr_time,
    delete tmr_move,
    delete tmr_spawn;
    drum.clear();
    emit clearDrum();
    emit gameEnd(score);
}

int Scene::gcd(int a, int b){
    a %= b;
    if(a==0) return b;
    else gcd(b,a);
}

