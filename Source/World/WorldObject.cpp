#include "WorldObject.h"

#include "../Util/Maths.h"

WorldObject::WorldObject(const sf::Vector2f& spriteSize, float speed)
:   m_speed (speed)
{
    m_sprite.setSize(spriteSize);
    m_sprite.setOrigin(spriteSize.x / 2, spriteSize.y / 2);
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
