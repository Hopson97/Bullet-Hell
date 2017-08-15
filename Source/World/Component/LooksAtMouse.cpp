#include "LooksAtMouse.h"

#include "../WorldObject.h"

LooksAtMouse::LooksAtMouse(WorldObject& object, const sf::RenderWindow& window)
:   ComponentBase   (object)
,   m_pWindow       (&window)
{ }

void LooksAtMouse::update(float dt)
{
    float mX = sf::Mouse::getPosition(*m_pWindow).x;
    float mY = sf::Mouse::getPosition(*m_pWindow).y;

    m_pObject->getSprite().lookAt(mX, mY);
}
