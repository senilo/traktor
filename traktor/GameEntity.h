#pragma once
#include "SFML\Graphics.hpp"
#include <string>

enum EntityStatus { ALIVE, DEAD };



class GameEntity
{
public:
    bool visible;
    bool blocking;
    std::string name;
    
    GameEntity();
    virtual EntityStatus update();
    virtual void draw(sf::RenderWindow &window);
};

