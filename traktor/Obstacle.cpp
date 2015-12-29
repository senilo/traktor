#include "Obstacle.h"


Obstacle::Obstacle(sf::Vector2f pos)
{
    this->pos = pos;
    this->name = "Obstacle";
    blocking = true;
    sprite = sf::RectangleShape(sf::Vector2f(BALL_SIZE, BALL_SIZE));
    sprite.setFillColor(sf::Color::Black);
    centerRectangleShapeOrigin(sprite);
    visible = true;

    sprite.setPosition(pos);
    globalBounds = sprite.getGlobalBounds();
    
}


Obstacle::~Obstacle()
{
}

void Obstacle::draw(sf::RenderWindow &window){
    window.draw(sprite);
}