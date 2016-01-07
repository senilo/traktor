#include "Assets.h"

std::unordered_map<std::string, sf::Texture> Assets::textures;

sf::Texture * Assets::getTexture(std::string name) {
	if (textures.count(name) == 1) {
		return &(textures[name]);
	}
	else {
		std::string path = "./assets/" + name;
		textures[name] = sf::Texture();
		textures[name].loadFromFile(path);
		textures[name].setSmooth(true);
		return &(textures[name]);	
	}
}