#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "../Util/Sprite.h"
#include "../Util/Animation.h"

class Player
{
    public:
        Player();

        void update         (float dt, const sf::RenderWindow& window);
        void moveForwards   ();
        void draw           (sf::RenderWindow& window);

    private:
        sf::Vector2f m_velocity;

        Sprite      m_sprite;
        Animation   m_walkAnim;

        sf::Texture m_textureTEMP;


};

#endif // PLAYER_H_INCLUDED
