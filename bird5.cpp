#include "bird5.h"

Bird5::Bird5(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void Bird5::skill()
{
    QPixmap big;
    big=QPixmap("://image/BIRD_GREY_YELL.png").scaled(960/32*2*2,540/18*2*2);
    g_pixmap.setPixmap(big);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(g_size.width()*2,g_size.height()*2);
    b2CircleShape bodyshape;
    bodyshape.m_radius = g_size.width()/2;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY*20;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->CreateFixture(&fixturedef);
}

