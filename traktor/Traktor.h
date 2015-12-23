#pragma once
#include "GameEntity.h"
class Traktor : public GameEntity
{
public:
    bool up, down, left, right;

    Traktor(std::string name);
    ~Traktor();

    virtual EntityStatus update();
    virtual void draw(sf::RenderWindow &window);
};

