#pragma once
#include "GameEntity.h"
#include "Ball.h"
class BallStack :
    public GameEntity
{
public:
    unsigned int num_vertical, num_horizontal, capacity;
    float spacing;
    std::list<Ball*> balls;
    sf::Sprite sprite;
    
    BallStack(sf::Vector2f pos);
    void draw(sf::RenderWindow &w);
    
    bool addBall(Ball *);
};

