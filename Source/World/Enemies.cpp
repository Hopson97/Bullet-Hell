#include "Enemies.h"

#include "../ResManager/ResourceHolder.h"

#include "Component/EnemyMoveAI.h"
#include "Component/LooksAtPlayer.h"
#include "Component/RandomSpawn.h"

BasicZombie::BasicZombie(WorldObject& player)
:   WorldObject (ResourceHolder::get().textures.get("Zombie"), {64, 32}, 5)
{
    addComponent<LooksAtPlayer>   (*this, player);
    addComponent<EnemyMoveAI>     (*this, player);
    addComponent<RandomSpawn>     (*this);

    auto delay = sf::seconds(0.4);
    m_walkAnimation.addFrame(0, 0, delay);
    m_walkAnimation.addFrame(1, 0, delay);
    m_walkAnimation.addFrame(2, 0, delay);
    m_walkAnimation.addFrame(1, 0, delay);
    getSprite().setTextureRect(m_walkAnimation.getCurrentFrame());
}
