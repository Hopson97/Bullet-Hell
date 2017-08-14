#include "Player.h"

#include "../Util/Maths.h"

Player::Player()
{
    m_sprite.setSize({16, 32});
    m_sprite.setPosition(150, 150);
    m_sprite.setOrigin(16 / 2, 32 / 2);
}

void Player::update(float dt, const sf::RenderWindow& window)
{
    m_sprite.move(m_velocity * dt);
    m_velocity *= 0.95f;

    float mX = sf::Mouse::getPosition(window).x;
    float mY = sf::Mouse::getPosition(window).y;

    float dX = m_sprite.getPosition().x - mX;
    float dY = m_sprite.getPosition().y - mY;

    m_rotation = std::atan2(dY, dX);
}

void Player::moveForwards()
{
    float x = -std::cos(m_rotation) * 10;
    float y = -std::sin(m_rotation) * 10;

    m_velocity += {x, y};
}

void Player::draw(sf::RenderWindow& win)
{
    m_sprite.setRotation(toDegrees(m_rotation) + 180);
    win.draw(m_sprite);
}


