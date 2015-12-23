#pragma once
#include "SFML\Graphics.hpp"
#include "GameEntity.h"
#include <list>
#include <memory>

enum GameStatus { CONTINUE, END };

class Game
{
public:
    bool up, down, left, right;
    std::list <std::shared_ptr<GameEntity>> game_objects;
    sf::Color background_color; 
    Game();
    GameStatus update();
    void draw(sf::RenderWindow &window);

};

