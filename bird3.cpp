#include "bird3.h"
#include <iostream>
Bird3::Bird3(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)

{

}



void Bird3::skill()
{
    g_body->SetLinearVelocity(b2Vec2(float (g_body->GetLinearVelocity().x)*1,float (g_body->GetLinearVelocity().y)*50));
    std::cout<<"a"<<std::endl;
}


