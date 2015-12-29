#include "GameEntity.h"


GameEntity::GameEntity() {
}


EntityStatus GameEntity::update() {
    return EntityStatus::ALIVE;
}
void GameEntity::draw(sf::RenderWindow &window){
}
