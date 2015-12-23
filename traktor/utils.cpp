#include "utils.h"

/*
Some vector functions
*/
float length(sf::Vector2f &v){
    return std::sqrt(v.x*v.x + v.y*v.y);
}

void set_length(sf::Vector2f &v, float new_length){
    v = v / length(v) * new_length;
}

sf::Vector2f fromPolar(float length, float angle){
    return sf::Vector2f(length*std::cos(angle), length*std::sin(angle));
}

// Set origin to center
void centerTextOrigin(sf::Text &text){
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
}