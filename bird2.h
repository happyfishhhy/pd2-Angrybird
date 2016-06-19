#ifndef BIRD2_H
#define BIRD2_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>


class Bird2 : public Bird
{
public:
    Bird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
     void skill();
};

#endif // BIRD2_H
