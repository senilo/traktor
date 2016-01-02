#include "BallStack.h"


BallStack::BallStack(sf::Vector2f pos) : num_vertical(4), num_horizontal(8)
{
    capacity = num_vertical * num_horizontal;
    this->pos = pos;
    this->name = std::string("Stroh Miete");
    blocking = true;
    visible = true;
    active = true;



    sprite = sf::RectangleShape(sf::Vector2f((num_horizontal + 1) * BALL_SIZE, (num_vertical + 1) * BALL_SIZE));
    sprite.setFillColor(sf::Color::Blue);
    sprite.setPosition(pos);

    globalBounds = sprite.getGlobalBounds();

}

void BallStack::draw(sf::RenderWindow &w){
    w.draw(sprite);
}

bool BallStack::addBall(Ball *b){
    if (balls.size() >= capacity){
        return false;
    }
    
    int row = balls.size() / num_horizontal + 1;
    int col = balls.size() % num_horizontal + 1;
    auto ball_pos = sf::Vector2f(col*BALL_SIZE,row*BALL_SIZE);
    b->sprite.setPosition(ball_pos + pos);
    b->sprite.setRotation(0.f);
    balls.push_back(b);
    return true;
}
