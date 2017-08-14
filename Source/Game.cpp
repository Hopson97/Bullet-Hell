#include "Game.h"

#include "States/StatePlaying.h"

Game::Game()
:   m_window    ({1280, 720}, "Bullet Hell")
{
    pushState<StatePlaying>(*this);
}

void Game::runLoop()
{
    sf::Clock clock;
    while (m_window.isOpen())
    {
        auto deltaTime  = clock.restart();
        auto& state     = getCurrentState();

        state.handleInput();
        state.update(deltaTime.asSeconds());

        m_window.clear();
        state.render(m_window);
        m_window.display();

        handleWinEvents(state);
    }
}

StateBase& Game::getCurrentState()
{
    return *m_states.back();
}

void Game::handleWinEvents(StateBase& state)
{
    sf::Event e;
    while (m_window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
        {
            m_window.close();
        }
        state.handleInput(e);
    }
}

