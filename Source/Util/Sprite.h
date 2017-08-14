#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <SFML/Graphics.hpp>

class Sprite : public sf::RectangleShape
{
    public:
        void lookAt(int worldX, int worldY);
};

#endif // SPRITE_H_INCLUDED
