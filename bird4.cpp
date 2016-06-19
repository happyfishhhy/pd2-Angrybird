#include "bird4.h"

Bird4::Bird4(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}


void Bird4::skill()
{
    g_body->SetLinearVelocity(b2Vec2(float (g_body->GetLinearVelocity().x)*(-50),float (g_body->GetLinearVelocity().y)*1));
}

