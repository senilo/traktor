#include "Assets.h"

bool Assets::loaded = false;
std::unordered_map<std::string, sf::Texture> Assets::textures = {
	{ "traktor.png", sf::Texture() },
	{ "ball.png", sf::Texture() },
	{ "wagon.png", sf::Texture() },
	{ "sten.png", sf::Texture() }
};


sf::Texture * Assets::getTexture(std::string name) {
	if (!loaded) {
		for (auto iter = textures.begin(); iter != textures.end(); iter++) {
			std::string name = "./assets/" + iter->first;
			iter->second.loadFromFile(name);
		}
		loaded = true;
	}

	if (textures.count(name) == 1) {
		return &(textures[name]);
	}
	else {
		return nullptr;
	}


}