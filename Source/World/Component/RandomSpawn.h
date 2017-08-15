#ifndef RANDOMSPAWN_H_INCLUDED
#define RANDOMSPAWN_H_INCLUDED

#include <random>

#include "ComponentBase.h"

class RandomSpawn : public ComponentBase
{
    public:
        RandomSpawn(WorldObject& object);

        void update(float dt){}

    private:
        static std::mt19937 m_randomEngine;
};

#endif // RANDOMSPAWN_H_INCLUDED
