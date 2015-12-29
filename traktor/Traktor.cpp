#include "Traktor.h"
#include "Utils.h"
#include <typeinfo>
#include "Ball.h"
#include "Wagon.h"

Traktor::Traktor(std::string name, sf::Vector2f pos)
{
    this->pos = pos;
    this->name = name;
    sprite = sf::RectangleShape(sf::Vector2f(TRAKTOR_LENGTH, TRAKTOR_WIDTH));
    sprite.setFillColor(sf::Color(52,173,0));

    centerRectangleShapeOrigin(sprite);
    sprite.setOrigin(TRAKTOR_ORIGIN_X, TRAKTOR_WIDTH / 2);
    orientation = 0.f;
    visible = true;

    sprite.setPosition(pos);
    sprite.setRotation(rad2deg(orientation));
    globalBounds = sprite.getGlobalBounds();
}


Traktor::~Traktor()
{
}

EntityStatus Traktor::update(){
    sf::Vector2f old_pos(pos);
    float old_orientation = orientation;
    sf::Vector2f dir;
    if (up) dir.y -= 1;
    if (down) dir.y += 1;
    if (left) dir.x -= 1;
    if (right) dir.x += 1;
    if (length(dir) > 0.0){
        pos = pos + dir / length(dir) * speed;
    }

    sprite.setPosition(pos);
    if (old_pos != pos){
        orientation = atan2((pos - old_pos).y, (pos - old_pos).x);
        sprite.setRotation(rad2deg(orientation));
        globalBounds = sprite.getGlobalBounds();

        for (auto obj : game_objects){
            if (obj.get() != this){
                if (globalBounds.intersects(obj->globalBounds)){
                    if (obj->blocking){
                        pos = old_pos;
                        orientation = old_orientation;
                        sprite.setPosition(pos);
                        sprite.setRotation(rad2deg(old_orientation));
                    }
                    else if (typeid(*obj) == typeid(Ball) && obj->active){
                        if (!connected_wagon->addBall(dynamic_cast<Ball*>(obj.get())) ){
                            pos = old_pos;
                            orientation = old_orientation;
                            sprite.setPosition(pos);
                            sprite.setRotation(rad2deg(old_orientation));
                        }
                        //obj->visible = false;
                    }
                }
            }
        }
    }
   
    up = down = left = right = false;
    return EntityStatus::ALIVE;
}

void Traktor::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

