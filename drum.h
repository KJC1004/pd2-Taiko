#ifndef DRUM_H
#define DRUM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Drum : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Drum(QObject *parent = 0);
    int ID, hit;
    QPixmap *explosion[2][17];

private slots:
    void move();
    void animate();

private:
    const static int step = -5;
    int frame = 0;
};

#endif // DRUM_H
