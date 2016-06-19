#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <gameitem.h>
#include <QGraphicsScene>
class BACKGROUND : public GameItem
{
public:
    BACKGROUND(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BACKGROUND_H
