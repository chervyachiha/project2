#pragma once

class Point
{
protected:
    float X;
    float Y;
public:
    Point(float x, float y);
    float x();
    float y();
    ~Point();
};