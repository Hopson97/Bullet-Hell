#ifndef LOOKSATPLAYER_H_INCLUDED
#define LOOKSATPLAYER_H_INCLUDED

#include "ComponentBase.h"

class LooksAtPlayer : public ComponentBase
{
    public:
        LooksAtPlayer(WorldObject& object, WorldObject& player);

        void update(float dt);

    private:
        WorldObject* m_pPlayer;
};

#endif // LOOKSATPLAYER_H_INCLUDED
