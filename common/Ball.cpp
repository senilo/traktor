#include "Ball.h"
#include "Assets.h"
int Ball::num_balls = 0;

Ball::Ball(sf::Vector2f pos)
{
    num_balls++;
    this->pos = pos;
    this->name = std::string("ball_") + std::to_string(num_balls);
    blocking = true;
    visible = true;
    active = true;

	sprite = sf::Sprite(*Assets::getTexture("ball.png"));
	sprite.setOrigin(BALL_SIZE / 2, BALL_SIZE / 2);

    orientation =  PI*((float) random_double() - 0.5f);
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
