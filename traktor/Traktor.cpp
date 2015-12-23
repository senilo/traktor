#include "Traktor.h"
#include "Utils.h"

Traktor::Traktor(std::string name, sf::Vector2f pos) : pos(pos)
{
    this->name = name;
    sprite = sf::RectangleShape(sf::Vector2f(TRAKTOR_LENGTH, TRAKTOR_WIDTH));
    sprite.setFillColor(sf::Color::Green);

    centerRectangleShapeOrigin(sprite);
    orientation = 0.f;
    visible = true;
}


Traktor::~Traktor()
{
}

EntityStatus Traktor::update(){
    sf::Vector2f old_pos(pos);
    if (up) pos.y -= speed;
    if (down) pos.y += speed;
    if (left) pos.x -= speed;
    if (right) pos.x += speed;
    if (old_pos != pos){
        orientation = atan2((pos - old_pos).y, (pos - old_pos).x);
    }

    sprite.setPosition(pos);
    sprite.setRotation(rad2deg(orientation));
    up = down = left = right = false;
    return EntityStatus::ALIVE;
}

void Traktor::draw(sf::RenderWindow &window){
    window.draw(sprite);
}
