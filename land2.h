#ifndef LAND2_H
#define LAND2_H

#include <gameitem.h>
#include <QGraphicsScene>

class land2 : public GameItem
{
public:
    land2(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // LAND2_H
