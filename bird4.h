#ifndef BIRD4_H
#define BIRD4_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>


class Bird4 : public Bird
{
public:
    Bird4(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

    virtual void skill();
};

#endif // BIRD4_H
