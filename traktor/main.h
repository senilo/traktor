#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <cmath>
#include <fstream>
#include <memory>
#include "GameEntity.h"
#include "Traktor.h"
// Globals
int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
char* TITLE = "Traktor";
sf::Color background_color(247, 255, 25);
sf::Color ball_color(183, 183, 22);

std::list <std::shared_ptr<GameEntity>> game_objects;
std::shared_ptr<Traktor> p1_traktor;

enum GameStatus { CONTINUE, END };

bool p1_up = false, p1_down = false, p1_left = false, p1_right = false;


int main();
GameStatus update();
void draw(sf::RenderWindow &window);

