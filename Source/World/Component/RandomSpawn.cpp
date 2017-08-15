#include "RandomSpawn.h"

#include <ctime>

#include "../WorldObject.h"

std::mt19937 RandomSpawn::m_randomEngine(std::time(nullptr));

RandomSpawn::RandomSpawn(WorldObject& object)
:   ComponentBase   (object)
{
    std::uniform_real_distribution<float> dist(0, 1000);

    auto x = dist(m_randomEngine);
    auto y = dist(m_randomEngine);

    object.getSprite().setPosition(x, y);
}
