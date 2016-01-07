#pragma once
#include <unordered_map>
#include <string>
#include "SFML\Graphics.hpp"

namespace Assets {
	extern std::unordered_map<std::string, sf::Texture> textures;
	sf::Texture *getTexture(std::string name);
}

