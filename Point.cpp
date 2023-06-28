#include "Point.hpp"

Point::Point ( float x, float y) : X(x),Y(y) {}
float Point:: x()
{
    return X;
}
float Point:: y()
{
    return Y;
}
Point::~Point(){}