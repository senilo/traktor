/*
 Traktor
 Anton Olason 2015-12-23
*/

#include <SFML/Graphics.hpp>
#include <list>
#include <cmath>
#include <fstream>
#include <memory>
#include "GameEntity.h"

// Globals
int SCREEN_WIDTH = 600;
int SCREEN_HEIGHT = 600;
char* TITLE = "Traktor";
sf::Color background_color(247, 255, 25);
enum GameStatus { CONTINUE, END };

std::list <std::shared_ptr<GameEntity>> game_objects;
bool p1_up = false , p1_down, p1_left, p1_right;

/*
 Här börjar main!
*/
int main()
{
    // Redirect to a file
    std::ofstream file("stderr.log");
    std::streambuf* previous = sf::err().rdbuf(file.rdbuf());

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE);
    window.setVerticalSyncEnabled(true);

    sf::Font font;
    if (!font.loadFromFile("freefont/FreeSansBold.ttf")){
        sf::err() << "Could not open 'freefont/FreeSansBold.ttf'" << std::endl;
    }
    
    // game loop
    while (window.isOpen())
    {
        if (!window.hasFocus()){
            sf::sleep(sf::milliseconds(50));
            continue;
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) p1_up = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) p1_down = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) p1_left = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) p1_right = true;

        update();
        draw(window);

        window.display();
    }
    return 0;
}

GameStatus update(){
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

void draw(sf::RenderWindow &window){
    window.clear(background_color);
    for (auto object : game_objects){
        if ((*object).visible == true){

        }
    }
}