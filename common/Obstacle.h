#pragma once
#include "GameEntity.h"
#include "Assets.h"
class Obstacle :
    public GameEntity
{
public:
    Obstacle(sf::Vector2f pos);
    ~Obstacle();
    void draw(sf::RenderWindow &window);
    sf::Sprite sprite;
};

