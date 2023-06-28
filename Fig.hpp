#pragma once
#include "Point.hpp"
#include <vector>

class Fig
{
protected:
    double m_area;
    std::vector <Point> m_size; ///вершины многоугольника
    int X, Y; ///Координаты центра
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
};
class Polygon: public Fig {
public:
    Polygon(const std::vector<Point> *size);
    virtual ~Polygon();
    double GetArea();
    int SGN(Point p1, Point p2, Point p);
    bool PointOnFig(Point p);
    int Convex();
    /*double OrArea(Point a,Point b, Point c);
    double dist (Point p1, Point p2);
    void quick_sort_dist(std::vector<double> D_x, std::vector<double> D_y, double di[], int l, int r);
    void quick_sort_angle(double angle[], std::vector<double> D_x, std::vector<double> D_y, double di[], int l, int r);
    int Graham(std::vector<Point> d);*/
};