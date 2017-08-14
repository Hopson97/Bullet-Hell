#include "StatePlaying.h"

#include <iostream>

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
{

}

void StatePlaying::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        m_player.moveForwards();
    }
}

void StatePlaying::update(float dt, const sf::RenderWindow& window)
{
    m_player.update(dt, window);
}

void StatePlaying::render(sf::RenderWindow& window)
{

    m_player.draw(window);
}
