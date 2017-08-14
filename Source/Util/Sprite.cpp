#include "Sprite.h"

#include "Maths.h"

void Sprite::lookAt(int worldX, int worldY)
{
    float dX = getPosition().x - worldX;
    float dY = getPosition().y - worldY;

    setRotation(toDegrees(std::atan2(dY, dX)) + 90);
}
