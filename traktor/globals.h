#include <list>
#include <memory>

// forward declaration
class GameEntity;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern char* TITLE;
const float TRAKTOR_WIDTH = 20.f;
const float TRAKTOR_LENGTH = 30.f;
const float BALL_SIZE = 10.f;

extern std::list <std::shared_ptr<GameEntity>> game_objects;
extern sf::Color background_color;
extern sf::Color ball_color;