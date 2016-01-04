#include "Traktor.h"
#include "Utils.h"
#include <typeinfo>
#include "Ball.h"
#include "Wagon.h"
#include "BallStack.h"

Traktor::Traktor(std::string name, sf::Vector2f pos)
{
    this->pos = pos;
    this->name = name;

	texture.loadFromFile("./assets/traktor.png");
	sprite = sf::Sprite(texture);
	sprite.setOrigin(TRAKTOR_ORIGIN_X, TRAKTOR_WIDTH / 2);

    sprite.setOrigin(TRAKTOR_ORIGIN_X, TRAKTOR_WIDTH / 2);
    orientation = 0.f;
    visible = true;

    sprite.setPosition(pos);
    sprite.setRotation(rad2deg(orientation));
    globalBounds = sprite.getGlobalBounds();
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
                    if (typeid(*obj) == typeid(Ball) && obj->active){
                        connected_wagon->addBall(dynamic_cast<Ball*>(obj.get()));
                    }
                    else if (typeid(*obj) == typeid(BallStack)){
                        connected_wagon->unloadBalls(dynamic_cast<BallStack*>(obj.get()));
                    }
                    
                    if (obj->blocking){
                        pos = old_pos;
                        orientation = old_orientation;
                        sprite.setPosition(pos);
                        sprite.setRotation(rad2deg(old_orientation));
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

