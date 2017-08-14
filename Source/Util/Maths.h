#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

template<typename T>
T toDegrees(T radians)
{
    return radians * (180 / 3.14159);
}

template<typename T>
T toRadians(T degrees)
{
    return degrees * (3.14159 / 180);
}

#endif // MATHS_H_INCLUDED
