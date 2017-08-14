#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player();

        void update         (float dt, const sf::RenderWindow& window);
        void moveForwards   ();
        void draw           (sf::RenderWindow& window);

    private:
        sf::RectangleShape m_sprite;

        sf::Vector2f m_velocity;

        float m_rotation;
};

#endif // PLAYER_H_INCLUDED
