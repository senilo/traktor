#pragma once
#include "GameEntity.h"

class Wagon;
class Traktor : public GameEntity
{
public:
    bool up, down, left, right;

    float speed = 2;
    Wagon *connected_wagon;
	sf::Texture texture;
	sf::Sprite sprite;

    Traktor(std::string name, sf::Vector2f pos);

    virtual EntityStatus update();
    virtual void draw(sf::RenderWindow &window);
};

