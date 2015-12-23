#pragma once
#include "GameEntity.h"
class Traktor : public GameEntity
{
public:
    bool up, down, left, right;
    sf::Vector2f pos;
    sf::RectangleShape sprite, sprite2;
    float orientation = 0;
    float speed = 2;

    Traktor(std::string name, sf::Vector2f pos);
    ~Traktor();

    virtual EntityStatus update();
    virtual void draw(sf::RenderWindow &window);
};

