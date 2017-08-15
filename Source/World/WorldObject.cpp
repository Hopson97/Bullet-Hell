#include "WorldObject.h"

#include "../Util/Maths.h"

WorldObject::WorldObject(const sf::Texture& t,
                         const sf::Vector2f& spriteSize,
                         float speed)
:   m_walkAnimation (32, 16)
,   m_speed (speed)
{
    m_sprite.setSize(spriteSize);
    m_sprite.setOrigin(spriteSize.x / 2, spriteSize.y / 2);
    m_sprite.setTexture(&t);
}


void WorldObject::update(float dt)
{
    for (auto& component : m_components)
    {
        component->update(dt);
    }

    m_sprite.move(m_velocity * dt);
    m_velocity *= 0.90f;
}

void WorldObject::moveForwards()
{
    float r = toRadians(m_sprite.getRotation() + 90);
    float x = std::cos(r) * m_speed;
    float y = std::sin(r) * m_speed;

    m_velocity += {x, y};
}

void WorldObject::draw(sf::RenderWindow& window)
{
    if (m_velocity.x > 0.5 || m_velocity.y > 0.5 ||
        m_velocity.x < 0.5 || m_velocity.y < 0.5)
    {
        m_sprite.setTextureRect(m_walkAnimation.getCurrentFrame());
    }
    window.draw(m_sprite);
}


Sprite& WorldObject::getSprite()
{
    return m_sprite;
}

const sf::Vector2f& WorldObject::getPosition() const
{
    return m_sprite.getPosition();
}
