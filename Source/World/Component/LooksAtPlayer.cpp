#include "LooksAtPlayer.h"

#include "../WorldObject.h"

LooksAtPlayer::LooksAtPlayer(WorldObject& object, WorldObject& player)
:   ComponentBase   (object)
,   m_pPlayer       (&player)
{ }

void LooksAtPlayer::update(float dt)
{
    //if player is alive
    m_pObject->getSprite().lookAt(m_pPlayer->getPosition().x, m_pPlayer->getPosition().y);

    //if player is dead
    //m_pObject->getSprite().lookAt(-m_pPlayer->getPosition().x, -m_pPlayer->getPosition().y);
}
