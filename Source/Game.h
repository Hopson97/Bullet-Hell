#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "States/StateBase.h"

class Game
{
    public:
        Game();

        void runLoop();

        const sf::RenderWindow& getWindow() const;

    private:
        StateBase& getCurrentState();
        void handleWinEvents(StateBase& state);

        template<typename T, typename... Args>
        void pushState(Args&&... args);

        std::vector<std::unique_ptr<StateBase>> m_states;

        sf::RenderWindow m_window;

};

template<typename T, typename... Args>
void Game::pushState(Args&&... args)
{
    m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
}


#endif // GAME_H_INCLUDED
