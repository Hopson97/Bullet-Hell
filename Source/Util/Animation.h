#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
    struct Frame
    {
        sf::IntRect frame;
        sf::Time    delay;
    };

    public:
        Animation(int frameWidth, int frameHeight);

        void addFrame(int xOffset, int yOffset, sf::Time delay);

        const sf::IntRect& getCurrentFrame();

    private:
        std::vector<Frame> m_frames;
        sf::Clock m_timer;
        unsigned m_currentFrame = 0;

        const int FRAME_WIDTH;
        const int FRAME_HEIGHT;
};

#endif // ANIMATION_H_INCLUDED
