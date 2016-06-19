#ifndef STONE_H
#define STONE_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define stone_DENSITY 10.0f
#define stone_FRICTION 0.5f
#define stone_RESTITUTION 0.5f

class STONE : public GameItem
{
public:
    STONE(float x, float y, float w, float h,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // STONE_H
