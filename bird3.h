#ifndef BIRD3_H
#define BIRD3_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>



class Bird3 : public Bird
{
public:
    Bird3(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

    virtual void skill();
};

#endif // BIRD3_H
