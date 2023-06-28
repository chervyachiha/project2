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

    void xy(double D_x[], double D_y[]);
    void quick_sort_angle(double angle[], double D_x[], double D_y[], double di[], int l, int r);
    void quick_sort_dist(double D_x[], double D_y[], double di[], int l, int r);
    int orsquare (int xA, int yA, int xB, int yB, int xC, int yC);
    double dist (double a1,double a2,double b1,double b2);
    void Gra(double *c_x, double *c_y, std::vector<Point> c);
};