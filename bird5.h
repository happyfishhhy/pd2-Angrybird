#ifndef BIRD5_H
#define BIRD5_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>

class Bird5 : public Bird
{
public:
    Bird5(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void skill();
};

#endif // BIRD5_H
