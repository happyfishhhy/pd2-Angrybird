#ifndef STONEB_H
#define STONEB_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define stoneb_DENSITY 1.0f
#define stoneb_FRICTION 0.5f
#define stoneb_RESTITUTION 0.5f

class STONEB : public GameItem
{
public:
    STONEB(float x, float y, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // STONEB_H
