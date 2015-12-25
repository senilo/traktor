#pragma once
#include "SFML\Graphics.hpp"
/*
Some vector functions
*/
float length(sf::Vector2f &v);

void set_length(sf::Vector2f &v, float new_length);
sf::Vector2f fromPolar(float length, float angle);

// Set origin to center
void centerTextOrigin(sf::Text &text);
void centerRectangleShapeOrigin(sf::RectangleShape &text);
float rad2deg(float angle);