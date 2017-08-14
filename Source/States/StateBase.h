#ifndef STATEBASE_H_INCLUDED
#define STATEBASE_H_INCLUDED

#include <SFML/Graphics.hpp>

class Game;

class StateBase
{
    public:
        StateBase(Game& game);

        virtual void handleInput(sf::Event e){};
        virtual void handleInput(){};

        virtual void update (float dt){};
        virtual void render (sf::RenderWindow& window){};

    protected:
        Game* m_pGame;
};

#endif // STATEBASE_H_INCLUDED
