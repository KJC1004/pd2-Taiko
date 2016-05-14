#include "drum.h"

Drum::Drum(QObject *parent) : QObject(parent)
{

}

void Drum::move(){
    moveBy(step,0);
}

void Drum::animate(){
    frame<17? setPixmap(*explosion[hit][frame++]): delete this;
}
