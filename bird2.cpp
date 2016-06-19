#include "bird2.h"

Bird2::Bird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}


void Bird2::skill()
{
    g_body->SetLinearVelocity(b2Vec2(float (g_body->GetLinearVelocity().x)*50,float (g_body->GetLinearVelocity().y)*1));
}
