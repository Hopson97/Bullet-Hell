#include "Game.h"

#include "States/StatePlaying.h"

Game::Game()
:   m_window    ({1280, 720}, "Bullet Hell")
{
    m_window.setFramerateLimit(60);
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
        state.update(deltaTime.asSeconds(), m_window);

        m_window.clear({50, 255, 40});
        state.render(m_window);
        m_window.display();

        handleWinEvents(state);
    }
}

const sf::RenderWindow& Game::getWindow() const
{
    return m_window;
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

