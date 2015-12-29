#include "Wagon.h"


Wagon::Wagon(Traktor *connected_to) : connected_to(connected_to)
{
    this->name = "Wagon";
    sprite = sf::RectangleShape(sf::Vector2f(WAGON_LENGTH, WAGON_WIDTH));
    sprite.setFillColor(sf::Color(42, 163, 0));
    centerRectangleShapeOrigin(sprite);
    sprite.setOrigin(WAGON_ORIGIN_X, WAGON_WIDTH / 2);
    orientation = connected_to->orientation;
    this->pos = connected_to->pos -
        (wagon_dist_to_coupling + traktor_dist_to_coupling)*fromPolar(1.f, orientation);
    connected_to->connected_wagon = this;
    
    sprite.setPosition(pos);
    sprite.setRotation(rad2deg(orientation));
    visible = true;
}
void Wagon::draw(sf::RenderWindow &w){
    w.draw(sprite);
}

EntityStatus Wagon::update(){
    sf::Vector2f coupling_pos = connected_to->pos -
        fromPolar(traktor_dist_to_coupling, connected_to->orientation);
    sf::Vector2f mov_dir = coupling_pos - pos;
    if (length(mov_dir) > 0.f){
        orientation = std::atan2(mov_dir.y, mov_dir.x);
        float diff = (length(mov_dir) - wagon_dist_to_coupling);
        if (diff > 0){
            pos = pos + mov_dir / length(mov_dir) * diff;
        }
        sprite.setPosition(pos);
        sprite.setRotation(rad2deg(orientation));
    }

    sf::Transform t = sprite.getTransform();
    auto iter = balls.begin();
    for (int i = 0; i < balls.size(); i++){
        int row = i / 2;
        int col = i % 2;
        Ball *ball = *iter;
        auto ball_pos = t.transformPoint(WAGON_ORIGIN_X + WAGON_LENGTH / 5 * row, WAGON_WIDTH/2 + (col - 0.5f) * WAGON_WIDTH / 2);
        ball->sprite.setPosition(ball_pos);
        ball->sprite.setRotation(this->sprite.getRotation());
       
        iter++;
    }

    return EntityStatus::ALIVE;

}

Wagon::~Wagon()
{
}

bool Wagon::addBall(Ball *ball){
    if (!ball->active)
        return false;
    if (balls.size() == 8){
        return false;
    }
    ball->active = false;
    balls.push_back(ball);
    return true;
}