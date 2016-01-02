#pragma once
#include <list>
#include "GameEntity.h"
#include "Traktor.h"
#include "Ball.h"
#include "BallStack.h"
class Wagon :
    public GameEntity
{
public:
    std::list<Ball*> balls;
    float wagon_dist_to_coupling = (WAGON_LENGTH - WAGON_ORIGIN_X + WAGON_SPACING);
    sf::RectangleShape sprite;
    Traktor *connected_traktor;
    bool connected_to_traktor;
    Wagon *connected_wagon;
    Wagon *trailer;

    void init();
    Wagon(Traktor * connected_to);
    Wagon(Wagon *connected_to);
    ~Wagon();
    void draw(sf::RenderWindow &w);
    EntityStatus update();
    bool addBall(Ball *);
    void Wagon::unloadBalls(BallStack *bs);
};

