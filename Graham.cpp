#include <math.h>
#include <iostream>
#include <vector>
#include "Point.hpp"
#include "Graham.hpp"

Graham::Graham (const std::vector<Point>* v) :  m_v(*v) {}
Graham::~Graham() {}

void Graham::quick_sort_angle(std::vector<double> angle, std::vector<Point> D, std::vector<double> di, int l, int r) {
    if (l>=r) return;
    double x=angle[l+(rand()%(r-l+1))];
    int i = l;
    int j = r;
    while(i <= j){
        while(angle[i] > x) i++;
        while(angle[j] < x) j--;
        if(i <= j) {
            std::swap(angle[i], angle[j]);
            std::swap(D[i],D[j]);
            std::swap(di[i],di[j]);
            i++;
            j--;
        }
    }
    quick_sort_angle(angle,D, di, i, r);
    quick_sort_angle(angle,D, di, l, j);
}

void Graham::quick_sort_dist(std::vector<Point> D, std::vector<double> di, int l, int r) {
    if (l>=r) return;
    double x=di[l+(rand()%(r-l+1))];
    int i = l;
    int j = r;
    while(i <= j){
        while(di[i] < x) i++;
        while(di[j] > x) j--;
        if(i <= j) {
            std::swap(di[i],di[j]);
            std::swap(D[i],D[j]);
            i++;
            j--;
        }
    }
    quick_sort_dist(D, di,i, r);
    quick_sort_dist(D, di,l, j);
}

int Graham::orsquare (Point a, Point b, Point c){
    return ((b.x()*c.y())+(a.x()*b.y())+(a.y()*c.x())-(b.x()*a.y())-(c.x()*b.y())-(a.x()*c.y()));
}

double Graham::dist (Point a,Point b){
    return sqrt((a.y()-a.x())*(a.y()-a.x())+(b.y()-b.x())*(b.y()-b.x()));
}

int Graham::Gra(std::vector<Point> D, std::vector<Point> c)
{
    int n = m_v.size();
    std::vector<double> angle ={};
    std::vector<double> di={};
    double min_x=INT_MAX,min_y=INT_MAX;
    int min_i=INT_MAX;
    for (int i=0;i<n;i++){
        if (D[i].x()<min_x) {min_x=D[i].x(); min_y=D[i].y(); min_i=i;}
        if (D[i].x()==min_x && D[i].y()<min_y) {min_x=D[i].x(); min_y=D[i].y(); min_i=i;}
    }
    std::swap(D[0],D[min_i]);
    for (int i=1; i<n;i++){
        if (D[i].x()-D[0].x()==0) angle[i]=INT_MAX;
        else  angle[i]=(D[i].y()-D[0].y())/(D[i].x()-D[0].x());
        di[i]=dist(D[i],D[0]);
    }
    quick_sort_angle(angle,D, di,1,n-1);
    for (int i=1;i<n-1;i++){
        if (angle[i]==angle[i+1]){
            int start=i;
            while (angle[i]==angle[i+1] && i<n-2) i++;
            int finish=i;
            quick_sort_dist(D, di,start,finish);
        }
    }
    D[n]=D[0];

    c[0]=D[0];
    c[1]=D[1];
    c[2]=D[2];
    int m=1;
    for (int i=2;i<=n;i++){
        while (orsquare(c[m-1],c[m],D[i])>0){
            m--;
        }
        m++;
        c[m]=D[i];
    }
    return m;
}