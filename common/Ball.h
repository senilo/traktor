#pragma once
#include "GameEntity.h"
#include "Utils.h"

class Ball :
    public GameEntity
{
private:
    static int num_balls;
public:
    sf::Sprite sprite;
    Ball(sf::Vector2f pos);
    void draw(sf::RenderWindow &window);
    ~Ball();
};

