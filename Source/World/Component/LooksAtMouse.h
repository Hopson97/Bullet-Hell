#ifndef LOOKSATMOUSE_H_INCLUDED
#define LOOKSATMOUSE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "ComponentBase.h"

class LooksAtMouse : public ComponentBase
{
    public:
        LooksAtMouse(WorldObject& object, const sf::RenderWindow& window);

        void update(float dt) override;

    private:
        const sf::RenderWindow* m_pWindow;
};

#endif // LOOKSATMOUSE_H_INCLUDED
