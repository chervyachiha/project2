#pragma once
#include "Point.hpp"
#include <vector>

class Fig
{
protected:
    double m_area;
    std::vector <Point> m_size; ///вершины многоугольника
    Fig(const std::vector<Point>* v);
    virtual ~Fig();
};

class Triangle: public Fig
{
public:
    Triangle(const std::vector<Point>* size);
    virtual ~Triangle();
    double GetSide(int n0, int n1);
    int Check();
    double GetPerimeter();
    double GetArea();
    double OrArea();
    void Draw();
};
class Polygon: public Fig {
public:
    Polygon(const std::vector<Point> *size);
    virtual ~Polygon();
    double GetArea();
    int SGN(Point p1, Point p2, Point p);
    bool PointOnFig(Point p);
    int Convex();
    void Draw(Point l);
};