#ifndef STATEPLAYING_H_INCLUDED
#define STATEPLAYING_H_INCLUDED

#include "StateBase.h"
#include "../World/WorldObject.h"

class StatePlaying : public StateBase
{
    public:
        StatePlaying(Game& game);

        void handleInput() override;
        void update(float dt, const sf::RenderWindow& window) override;
        void render(sf::RenderWindow& window) override;

    private:
        WorldObject m_player;

        std::vector<WorldObject> m_worldObjects;


};

#endif // STATEPLAYING_H_INCLUDED
