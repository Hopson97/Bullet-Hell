#ifndef ENEMIES_H_INCLUDED
#define ENEMIES_H_INCLUDED

#include "WorldObject.h"

class BasicZombie : public WorldObject
{
    public:
        BasicZombie(WorldObject& player);
};

#endif // ENEMIES_H_INCLUDED
