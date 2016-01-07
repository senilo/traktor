/*
Traktor
Anton Olason 2015-12-23
*/
#include <list>
#include <cmath>
#include <fstream>
#include <memory>
#include <random>
#include <functional>
#include <ctime>

#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Traktor.h"
#include "Ball.h"
#include "Obstacle.h"
#include "Wagon.h"


char* TITLE = "Traktor";
sf::Color background_color(247, 255, 25);
sf::Color ball_color(183, 183, 22);

std::list <std::shared_ptr<GameEntity>> game_objects;
std::list <sf::Sprite> background_objects;
std::shared_ptr<Traktor> p1_traktor;


enum GameStatus { CONTINUE, END };

bool p1_up = false, p1_down = false, p1_left = false, p1_right = false;

std::default_random_engine generator((unsigned int)time(0));
std::uniform_real_distribution<double> distribution(0.0, 1.0);
auto rng = std::bind(distribution, generator);


double _random() {
	return rng();
}
double(*random_double)() = _random;

int main();
int init_game();
GameStatus update();
void draw(sf::RenderWindow &window);

int main()
{
	// Redirect to a file
	std::ofstream file("stderr.log");
	std::streambuf* previous = sf::err().rdbuf(file.rdbuf());

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE);
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	if (!font.loadFromFile("freefont/FreeSansBold.ttf")) {
		sf::err() << "Could not open 'freefont/FreeSansBold.ttf'" << std::endl;
	}


	init_game();
	// game loop
	while (window.isOpen())
	{
		if (!window.hasFocus()) {
			sf::sleep(sf::milliseconds(50));
			continue;
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
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

int init_game() {
	p1_traktor = std::shared_ptr<Traktor>(new Traktor("player 1 traktor", sf::Vector2f(100.0f, 100.0f)));
	game_objects.push_back(p1_traktor);
	auto wagon1 = std::shared_ptr<Wagon>(new Wagon(p1_traktor.get()));
	game_objects.push_back(wagon1);
	game_objects.push_back(std::shared_ptr<Wagon>(new Wagon(wagon1.get())));
	game_objects.push_back(std::shared_ptr<BallStack>(new BallStack(sf::Vector2f(100, 300))));

	for (int num_added = 0; num_added < 80;) {
		bool ok = true;
		float x = (float)rng() * SCREEN_WIDTH;
		float y = (float)rng() * SCREEN_HEIGHT;
		auto new_ball = std::shared_ptr<Ball>(new Ball(sf::Vector2f(x, y)));
		for (auto object : game_objects) {
			if (new_ball->globalBounds.intersects(object->globalBounds)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			game_objects.push_back(new_ball);
			num_added++;
		}

	}
	for (int num_added = 0; num_added < 8;) {
		bool ok = true;
		float x = (float)rng() * SCREEN_WIDTH;
		float y = (float)rng() * SCREEN_HEIGHT;
		auto new_obstacle = std::shared_ptr<Obstacle>(new Obstacle(sf::Vector2f(x, y)));
		for (auto object : game_objects) {
			if (new_obstacle->globalBounds.intersects(object->globalBounds)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			game_objects.push_back(new_obstacle);
			num_added++;
		}
	}

	sf::Sprite field(*Assets::getTexture("field.png"));
	int _field_height = field.getLocalBounds().height;
	int _field_width = field.getLocalBounds().width;
	for (int row = 0; row < SCREEN_HEIGHT / _field_height; row++) {
		for (int col = 0; col < SCREEN_WIDTH / _field_height; col++) {
			background_objects.push_back(sf::Sprite(field));
			background_objects.back().setPosition(col*_field_width, row*_field_height);
		}
	}
	//background_objects
	return 0;
}

GameStatus update() {
	for (auto iter = game_objects.begin(); iter != game_objects.end();) {
		EntityStatus status = (*iter)->update();
		if (status == ALIVE) {
			iter++;
		}
		else {
			iter++;
		}
	}
	return GameStatus::CONTINUE;
}

void draw(sf::RenderWindow &window) {
	window.clear(background_color);
	for (auto sprite : background_objects) {
		window.draw(sprite);
	}
	for (auto object : game_objects) {
		if ((*object).visible == true) {
			object->draw(window);
		}
	}
}