#pragma once
#include "GameEntity.h"

class Wagon;
class Traktor : public GameEntity
{
public:
    bool up, down, left, right;
    sf::RectangleShape sprite, sprite2;
    float speed = 2;
    Wagon *connected_wagon;

    Traktor(std::string name, sf::Vector2f pos);
    ~Traktor();

    virtual EntityStatus update();
    virtual void draw(sf::RenderWindow &window);
};

