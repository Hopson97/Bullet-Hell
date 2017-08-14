#include "Player.h"

#include "../Util/Maths.h"

Player::Player()
:   m_walkAnim  (32, 16)
{
    m_textureTEMP.loadFromFile("Resources/Textures/Player.png");
    m_sprite.setTexture(&m_textureTEMP);

    m_sprite.setSize({64, 32});
    m_sprite.setPosition(150, 150);
    m_sprite.setOrigin(64 / 2, 32 / 2);

    auto delay = sf::seconds(0.1);
    m_walkAnim.addFrame(0, 0, delay);
    m_walkAnim.addFrame(1, 0, delay);
    m_walkAnim.addFrame(2, 0, delay);
    m_walkAnim.addFrame(1, 0, delay);
}

void Player::update(float dt, const sf::RenderWindow& window)
{
    m_sprite.move(m_velocity * dt);
    m_velocity *= 0.90f;

    float mX = sf::Mouse::getPosition(window).x;
    float mY = sf::Mouse::getPosition(window).y;

    m_sprite.lookAt(mX, mY);
}

void Player::moveForwards()
{
    float r = toRadians(m_sprite.getRotation() + 90);
    float x = std::cos(r) * 10;
    float y = std::sin(r) * 10;

    m_velocity += {x, y};
}

void Player::draw(sf::RenderWindow& win)
{
    m_sprite.setTextureRect(m_walkAnim.getCurrentFrame());
    win.draw(m_sprite);
}


