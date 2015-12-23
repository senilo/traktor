/*
 Traktor
 Anton Olason 2015-12-23
*/
#include "main.h"

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

    p1_traktor = std::shared_ptr<Traktor>(new Traktor("player 1 traktor", sf::Vector2f(100.0f, 100.0f)));
    game_objects.push_back(p1_traktor);
    
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) p1_traktor->up = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) p1_traktor->down = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) p1_traktor->left = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) p1_traktor->right = true;

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
            object->draw(window);
        }
    }
}