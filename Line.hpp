#pragma once
#include "Point.hpp"

class Line
{
protected:
    Point P1;
    Point P2;
public:
    Line(Point p1, Point p2);
    ~Line();
    Point Start();
    Point Finish();
    float GetLength();
    int SGN(Point p1,Point p2, Point p);
    int Intersection(Point p1, Point p2,Point p3, Point p4);
    bool PointOnSegment(float x1,float y1,float x2,float y2,float x,float y);
};