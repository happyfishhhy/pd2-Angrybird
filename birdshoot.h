#ifndef BIRDSHOOT_H
#define BIRDSHOOT_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRDSHOOT_DENSITY 50.0f
#define BIRDSHOOT_FRICTION 0.2f
#define BIRDSHOOT_RESTITUTION 0.5f

class BirdShoot : public GameItem
{
public:
    BirdShoot(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
};

#endif // BIRDSHOOT_H
