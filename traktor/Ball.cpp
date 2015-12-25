#include "Ball.h"

int Ball::num_balls = 0;

Ball::Ball(sf::Vector2f pos)
{
    sprite = sf::RectangleShape(sf::Vector2f(BALL_SIZE, BALL_SIZE));
    sprite.setFillColor(ball_color);
    centerRectangleShapeOrigin(sprite);
    num_balls++;
    pos = pos;
    name = std::string("ball_") + std::to_string(num_balls);
}

void Ball::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

Ball::~Ball()
{
}
