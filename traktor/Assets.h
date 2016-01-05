#pragma once
#include <unordered_map>
#include <string>
#include "SFML\Graphics.hpp"

class Assets
{
private:
	static bool loaded;
	static std::unordered_map<std::string, sf::Texture> textures;
public:
	static sf::Texture *getTexture(std::string name);
};

