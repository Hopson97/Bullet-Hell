#include "Player.h"

#include "../ResManager/ResourceHolder.h"

Player::Player()
:   WorldObject (ResourceHolder::get().textures.get("Player"), {64, 32}, 10)
{
    getSprite().setPosition(150, 150);

    auto delay = sf::seconds(0.4);
    m_walkAnimation.addFrame(0, 0, delay);
    m_walkAnimation.addFrame(1, 0, delay);
    m_walkAnimation.addFrame(2, 0, delay);
    m_walkAnimation.addFrame(1, 0, delay);
    getSprite().setTextureRect(m_walkAnimation.getCurrentFrame());
}


