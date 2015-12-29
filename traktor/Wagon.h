#pragma once
#include <list>
#include "GameEntity.h"
#include "Traktor.h"
#include "Ball.h"
class Wagon :
    public GameEntity
{
public:
    std::list<Ball*> balls;
    float wagon_dist_to_coupling = (WAGON_LENGTH - WAGON_ORIGIN_X + WAGON_SPACING);
    float traktor_dist_to_coupling = (TRAKTOR_ORIGIN_X);
    sf::RectangleShape sprite;
    Traktor *connected_to;

    Wagon(Traktor * connected_to);
    ~Wagon();
    void draw(sf::RenderWindow &w);
    EntityStatus update();
    bool addBall(Ball *);
};

