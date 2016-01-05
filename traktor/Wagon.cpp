#include "Wagon.h"
#include "Assets.h"
void Wagon::init(){
    name = "Wagon";
	sprite = sf::Sprite(*Assets::getTexture("wagon.png"));
	sprite.setOrigin(WAGON_ORIGIN_X, sprite.getLocalBounds().height / 2.0f);
    visible = true;
    trailer = 0;
}

Wagon::Wagon(Traktor *connected_to) : connected_traktor(connected_to), connected_wagon(nullptr)
{
    init();
    connected_to_traktor = true;
    orientation = connected_traktor->orientation;
    
    this->pos = connected_traktor->pos -
        (wagon_dist_to_coupling + TRAKTOR_ORIGIN_X)*fromPolar(1.f, orientation);
    connected_traktor->connected_wagon = this;
    
    sprite.setPosition(pos);
    sprite.setRotation(rad2deg(orientation));
}

Wagon::Wagon(Wagon *connected_to) : connected_wagon(connected_to), connected_traktor(nullptr){
    init();
    connected_to_traktor = false;
    connected_wagon->trailer = this;
    orientation = connected_wagon->orientation;

    this->pos = connected_wagon->pos -
        (wagon_dist_to_coupling + WAGON_ORIGIN_X)*fromPolar(1.f, orientation);

    sprite.setPosition(pos);
    sprite.setRotation(rad2deg(orientation));
}

void Wagon::draw(sf::RenderWindow &w){
    w.draw(sprite);
}

EntityStatus Wagon::update(){
    sf::Vector2f coupling_pos;
    if (connected_to_traktor){
        coupling_pos = connected_traktor->pos -
            fromPolar(TRAKTOR_ORIGIN_X, connected_traktor->orientation);
    }
    else{
        coupling_pos = connected_wagon->pos -
            fromPolar(WAGON_ORIGIN_X, connected_wagon->orientation);
    }
    sf::Vector2f mov_dir = coupling_pos - pos;
    if (length(mov_dir) > 0.f){
        orientation = std::atan2(mov_dir.y, mov_dir.x);
        float diff = (length(mov_dir) - wagon_dist_to_coupling);
        if (diff > 0){
            pos = pos + mov_dir / length(mov_dir) * diff;
        }
        sprite.setPosition(pos);
        sprite.setRotation(rad2deg(orientation));
    }

    sf::Transform t = sprite.getTransform();
    auto iter = balls.begin();
    for (unsigned int i = 0; i < balls.size(); i++){
        int row = i / 2;
        int col = i % 2;
        Ball *ball = *iter;
        auto ball_pos = t.transformPoint(WAGON_ORIGIN_X + WAGON_LENGTH / 5 * row, WAGON_WIDTH/2 + (col - 0.5f) * WAGON_WIDTH / 2);
        ball->sprite.setPosition(ball_pos);
        ball->sprite.setRotation(this->sprite.getRotation()+90.f);
       
        iter++;
    }

    return EntityStatus::ALIVE;

}

Wagon::~Wagon()
{
}

bool Wagon::addBall(Ball *ball){
    if (!ball->active)
        return false;
    if (balls.size() == 8){
        if (trailer != 0 && !trailer->addBall(ball)){
            return false;
        }
        else return true;
       
    }
    ball->active = false;
    ball->blocking = false;
    balls.push_back(ball);
    return true;
}

void Wagon::unloadBalls(BallStack *bs){
    for (auto iter = balls.begin();;) {
        if (iter == balls.end()){
            break;
        }
        if (!bs->addBall(*iter)){ // fails if stack is full
            return;
        }
        iter = balls.erase(iter);
    }
    if (trailer != 0){
        trailer->unloadBalls(bs);
    }
}