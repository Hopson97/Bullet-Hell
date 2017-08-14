#ifndef STATEPLAYING_H_INCLUDED
#define STATEPLAYING_H_INCLUDED

#include "StateBase.h"

class StatePlaying : public StateBase
{
    public:
        StatePlaying(Game& game);

        void handleInput();
        void update(float dt);
        void render(sf::RenderWindow& window);

};

#endif // STATEPLAYING_H_INCLUDED
