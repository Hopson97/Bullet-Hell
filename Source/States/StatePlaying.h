#ifndef STATEPLAYING_H_INCLUDED
#define STATEPLAYING_H_INCLUDED

#include "StateBase.h"
#include "../World/WorldObject.h"
#include "../World/Player.h"


class StatePlaying : public StateBase
{
    public:
        StatePlaying(Game& game);

        void handleInput() override;
        void update(float dt, const sf::RenderWindow& window) override;
        void render(sf::RenderWindow& window) override;

    private:
        Player m_player;

        std::vector<std::unique_ptr<WorldObject>> m_worldObjects;


};

#endif // STATEPLAYING_H_INCLUDED
