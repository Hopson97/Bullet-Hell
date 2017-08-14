#include "Animation.h"

Animation::Animation(int frameWidth, int frameHeight)
:   FRAME_WIDTH     (frameWidth)
,   FRAME_HEIGHT    (frameHeight)
{ }


void Animation::addFrame(int xOffset, int yOffset, sf::Time delay)
{
    Frame newFrame;
    newFrame.frame = {xOffset * FRAME_WIDTH,
                      yOffset * FRAME_HEIGHT,
                      FRAME_WIDTH, FRAME_HEIGHT};
    newFrame.delay = delay;

    m_frames.push_back(newFrame);
}

const sf::IntRect& Animation::getCurrentFrame()
{
    if (m_timer.getElapsedTime() > m_frames[m_currentFrame].delay)
    {
        m_currentFrame++;
        m_timer.restart();
        if (m_currentFrame == m_frames.size())
        {
            m_currentFrame = 0;
        }
    }

    return m_frames[m_currentFrame].frame;
}
