#include <list>
#include <memory>

// forward declaration
class GameEntity;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern char* TITLE;
const int TRAKTOR_WIDTH = 20;
const int TRAKTOR_LENGTH = 30;

extern std::list <std::shared_ptr<GameEntity>> game_objects;