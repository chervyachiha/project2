#pragma once

#include <math.h>
#include <iostream>
#include <vector>
#include "Point.hpp"

class Graham
{
protected:
    std::vector <Point> m_v;
public:
    Graham (const std::vector<Point>* v);
    ~Graham();
    void quick_sort_angle(std::vector<double> angle, std::vector<Point> D, std::vector<double> di, int l, int r);
    void quick_sort_dist(std::vector<Point> D, std::vector<double> di, int l, int r);
    int orsquare (Point a, Point b, Point c);
    double dist (Point a,Point b);
    int Gra(std::vector<Point> D, std::vector<Point> c);
};