#include "Obstacle.h"


Obstacle::Obstacle(sf::Vector2f pos)
{
    this->pos = pos;
    this->name = "Obstacle";
    blocking = true;
	sprite = sf::Sprite(*Assets::getTexture("sten.png"));
	sprite.setOrigin(10, 10);
    visible = true;

    sprite.setPosition(pos);
	sprite.setRotation(360.0f * random_double());
    globalBounds = sprite.getGlobalBounds();
    
}


Obstacle::~Obstacle()
{
}

void Obstacle::draw(sf::RenderWindow &window){
    window.draw(sprite);
}