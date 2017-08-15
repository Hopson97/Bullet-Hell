#ifndef ENEMYMOVEAI_H_INCLUDED
#define ENEMYMOVEAI_H_INCLUDED

#include "ComponentBase.h"

class EnemyMoveAI : public ComponentBase
{
    public:
        EnemyMoveAI(WorldObject& object, WorldObject& player);

        void update(float dt);

    private:
        WorldObject* m_pPlayer;
};

#endif // ENEMYMOVEAI_H_INCLUDED
