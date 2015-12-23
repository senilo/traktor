#include "Game.h"


Game::Game() : background_color(247, 255, 25){
}


GameStatus Game::update(){
    for (auto iter = game_objects.begin(); iter != game_objects.end();){
        EntityStatus status = (*iter)->update();
        if (status == ALIVE){
            iter++;
        }
        else {
            iter++;
        }
    }
    return GameStatus::CONTINUE;
}

void Game::draw(sf::RenderWindow &window){
    window.clear(background_color);
    for (auto object : game_objects){
        if ((*object).visible == true){

        }
    }
}