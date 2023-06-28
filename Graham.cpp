#include <math.h>
#include <iostream>
#include <vector>
#include "Point.hpp"
#include "Graham.hpp"

Graham::Graham (const std::vector<Point>* v) :  m_v(*v) {}
Graham::~Graham() {}
void Graham::xy(double D_x[], double D_y[])
{
    for (int i=0; i<m_v.size();i++)
    {
        D_x[i] = m_v[i].x();
        D_y[i] = m_v[i].y();
    }
}

void Graham::quick_sort_angle(double angle[], double D_x[], double D_y[], double di[], int l, int r) {
    if (l>=r) return;
    double x=angle[l+(rand()%(r-l+1))];
    int i = l;
    int j = r;
    while(i <= j){
        while(angle[i] > x) i++;
        while(angle[j] < x) j--;
        if(i <= j) {
            std::swap(angle[i], angle[j]);
            std::swap(D_x[i],D_x[j]);
            std::swap(D_y[i],D_y[j]);
            std::swap(di[i],di[j]);
            i++;
            j--;
        }
    }
    quick_sort_angle(angle,D_x, D_y, di, i, r);
    quick_sort_angle(angle,D_x, D_y, di, l, j);
}

void Graham::quick_sort_dist(double D_x[], double D_y[], double di[], int l, int r) {
    if (l>=r) return;
    double x=di[l+(rand()%(r-l+1))];
    int i = l;
    int j = r;
    while(i <= j){
        while(di[i] < x) i++;
        while(di[j] > x) j--;
        if(i <= j) {
            std::swap(di[i],di[j]);
            std::swap(D_x[i],D_x[j]);
            std::swap(D_y[i],D_y[j]);
            i++;
            j--;
        }
    }
    quick_sort_dist(D_x, D_y, di,i, r);
    quick_sort_dist(D_x, D_y, di,l, j);
}

int Graham::orsquare (int xA, int yA, int xB, int yB, int xC, int yC){
    return ((xB*yC)+(xA*yB)+(yA*xC)-(xB*yA)-(xC*yB)-(xA*yC));
}

double Graham::dist (double a1,double a2,double b1,double b2){
    return sqrt((a2-a1)*(a2-a1)+(b2-b1)*(b2-b1));
}

void Graham::Gra(double *c_x, double *c_y, std::vector<Point> c)
{
    double D_x[m_v.size()];
    double D_y[m_v.size()];
    xy(D_x,D_y);
    int n = m_v.size();
    double angle[2020], di[2020];
    double min_x=INT_MAX,min_y=INT_MAX;
    int min_i=INT_MAX;
    for (int i=0;i<n;i++){
        if (D_x[i]<min_x) {min_x=D_x[i]; min_y=D_y[i]; min_i=i;}
        if (D_x[i]==min_x && D_y[i]<min_y) {min_x=D_x[i]; min_y=D_y[i]; min_i=i;}
    }
    std::swap(D_x[0],D_x[min_i]);
    std::swap(D_y[0],D_y[min_i]);
    for (int i=1; i<n;i++){
        if (D_x[i]-D_x[0]==0) angle[i]=INT_MAX;
        else  angle[i]=(D_y[i]-D_y[0])/(D_x[i]-D_x[0]);
        di[i]=dist(D_x[i],D_x[0],D_y[i],D_y[0]);
    }
    quick_sort_angle(angle,D_x, D_y, di,1,n-1);
    for (int i=1;i<n-1;i++){
        if (angle[i]==angle[i+1]){
            int start=i;
            while (angle[i]==angle[i+1] && i<n-2) i++;
            int finish=i;
            quick_sort_dist(D_x, D_y, di,start,finish);
        }
    }
    D_x[n]=D_x[0];
    D_y[n]=D_y[0];

    c_x[0]=D_x[0];
    c_y[0]=D_y[0];
    c_x[1]=D_x[1];
    c_y[1]=D_y[1];
    c_x[2]=D_x[2];
    c_y[2]=D_y[2];
    int m=1;
    for (int i=2;i<=n;i++){
        while (orsquare(c_x[m-1], c_y[m-1],c_x[m], c_y[m],D_x[i], D_y[i])>0){
            m--;
        }
        m++;
        c_x[m]=D_x[i];
        c_y[m]=D_y[i];
    }
    for (int i=0; i<m;i++)
    {
        c.push_back(Point (c_x[i], c_y[i]));
    }
}