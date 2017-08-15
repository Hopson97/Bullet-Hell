#include "StatePlaying.h"

#include <iostream>

#include "../World/Component/LooksAtMouse.h"

#include "../Game.h"

#include "../World/Enemies.h"

StatePlaying::StatePlaying(Game& game)
:   StateBase       (game)
{
    m_player.addComponent<LooksAtMouse>(m_player, game.getWindow());

    for (int i = 0; i < 25; i++)
        m_worldObjects.push_back(std::make_unique<BasicZombie>(m_player));
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
    m_player.update(dt);

    for (auto& obj : m_worldObjects)
    {
        obj->update(dt);
    }
}

void StatePlaying::render(sf::RenderWindow& window)
{
    for (auto& obj : m_worldObjects)
    {
        obj->draw(window);
    }

    m_player.draw(window);
}
