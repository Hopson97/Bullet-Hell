#include "EnemyMoveAI.h"

#include "../WorldObject.h"


EnemyMoveAI::EnemyMoveAI(WorldObject& object, WorldObject& player)
:   ComponentBase   (object)
,   m_pPlayer       (&player)
{

}

void EnemyMoveAI::update(float dt)
{
    //if player is alive
    m_pObject->moveForwards();

    //if player is dead
}

