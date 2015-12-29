#include <list>
#include <memory>
#include "SFML\Graphics.hpp"
#include <random>

// forward declaration
class GameEntity;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern char* TITLE;
const float TRAKTOR_WIDTH = 20.f;
const float TRAKTOR_LENGTH = 30.f;
const float TRAKTOR_ORIGIN_X = TRAKTOR_LENGTH / 5;
const float WAGON_WIDTH = 20.f;
const float WAGON_LENGTH = 40.f;
const float WAGON_SPACING = 8.f;
const float WAGON_ORIGIN_X = WAGON_LENGTH / 5;
const float BALL_SIZE = 10.f;

extern std::list <std::shared_ptr<GameEntity>> game_objects;
extern sf::Color background_color;
extern sf::Color ball_color;

extern std::default_random_engine generator;
extern std::uniform_real_distribution<double> distribution;
extern double(*random_double)();