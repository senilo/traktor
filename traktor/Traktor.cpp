#include "Traktor.h"


Traktor::Traktor(std::string name)
{
    this->name = name;
}


Traktor::~Traktor()
{
}

EntityStatus Traktor::update(){
    if (up) {
        ;
    }
    
    up = down = left = right = false;
    return EntityStatus::ALIVE;
}

void Traktor::draw(sf::RenderWindow &window){
    ;
}
