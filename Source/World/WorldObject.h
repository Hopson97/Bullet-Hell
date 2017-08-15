#ifndef WORLDOBJECT_H_INCLUDED
#define WORLDOBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "../Util/Sprite.h"
#include "Component/ComponentBase.h"

class WorldObject
{
    public:
        WorldObject(const sf::Vector2f& spriteSize, float speed);

        Sprite& getSprite();
        const sf::Vector2f& getPosition() const;

        void moveForwards ();

        void update (float dt);
        void draw   (sf::RenderWindow& window);

        template<typename Comp, typename... Args>
        void addComponent(Args&&... args);

    private:
        std::vector<std::unique_ptr<ComponentBase>> m_components;

        Sprite m_sprite;
        sf::Vector2f m_velocity;

        float m_speed;
};

template<typename T, typename... Args>
void WorldObject::addComponent(Args&&... args)
{
    m_components.push_back(std::make_unique<T>(std::forward<Args>(args)...));
}

#endif // WORLDOBJECT_H_INCLUDED
