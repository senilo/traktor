#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include "globals.h"
#include "Utils.h"

enum EntityStatus { ALIVE, DEAD };



class GameEntity
{
public:
    bool visible;
    bool blocking;
    bool active;
    std::string name;
    sf::Vector2f pos;
    float orientation;
    sf::FloatRect globalBounds;
    
    GameEntity();
    virtual EntityStatus update();
    virtual void draw(sf::RenderWindow &window);

};

