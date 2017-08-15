#include "Enemies.h"

#include "Component/EnemyMoveAI.h"
#include "Component/LooksAtPlayer.h"
#include "Component/RandomSpawn.h"

BasicZombie::BasicZombie(WorldObject& player)
:   WorldObject ({32, 16}, 5)
{
    addComponent<LooksAtPlayer>   (*this, player);
    addComponent<EnemyMoveAI>     (*this, player);
    addComponent<RandomSpawn>     (*this);
}
