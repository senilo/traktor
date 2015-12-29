#include "Ball.h"

int Ball::num_balls = 0;

Ball::Ball(sf::Vector2f pos)
{
    num_balls++;
    this->pos = pos;
    this->name = std::string("ball_") + std::to_string(num_balls);
    blocking = false;
    visible = true;
    active = true;

    sprite = sf::RectangleShape(sf::Vector2f(BALL_SIZE, BALL_SIZE));
    sprite.setFillColor(ball_color);
    centerRectangleShapeOrigin(sprite);

    orientation = 0.1 * 3.14159*(random_double() - 0.5);
    sprite.setPosition(pos);
    sprite.setRotation(rad2deg(orientation));
    globalBounds = sprite.getGlobalBounds();
}

void Ball::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

Ball::~Ball()
{
}
