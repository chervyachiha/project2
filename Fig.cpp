#include "Point.hpp"
#include "Fig.hpp"
#include <iostream>
#include <vector>
#include <math.h>

Fig::Fig(const std::vector<Point>* v) :  m_size(*v) {}
Fig::~Fig() {}


Triangle::Triangle(const std::vector<Point>* size) : Fig(size) {}
Triangle::~Triangle(){}
double Triangle::GetSide(int n0, int n1)
{

    double a = sqrt(pow(m_size[n1].x()-m_size[n0].x(),2)+pow(m_size[n1].y()-m_size[n0].y(),2));
    return a;
}

int Triangle::Check()
{
    if (GetSide(0,1)+ GetSide(0,2)<= GetSide(1,2)|| GetSide(0,1)+ GetSide(1,2)<= GetSide(0,2)||
        GetSide(0,2)+ GetSide(1,2)<= GetSide(0,1))
    {
        std::cout << "Triangle doesn't exist"<<std::endl;
        return 0;
    }
    return 1;
}
double Triangle::GetPerimeter()
{
    double p = GetSide(0,1)+ GetSide(0,2)+GetSide(1,2);
    return p;
}
double Triangle::GetArea()
{
    double p = (GetPerimeter())/2;
    m_area = sqrt(p*(p- GetSide(0,1))*(p- GetSide(0,2))*(p- GetSide(1,2)));
    return m_area;
}
double Triangle::OrArea()
{
    m_area = 0.5*(m_size[1].x()*m_size[2].y()+m_size[0].x()*m_size[1].y()-m_size[1].x()*m_size[0].y()-m_size[2].x()*m_size[1].y()-m_size[0].x()*m_size[2].y()+m_size[0].y()*m_size[2].x());
    return m_area;
}

Polygon::Polygon(const std::vector<Point>* size) : Fig(size) {}
Polygon::~Polygon(){}
double Polygon::GetArea()
{
    float S = 0;
    m_size.emplace_back(m_size[0]);
    int q = m_size.size();
    //m_size[q].x() = m_size[0].x();
    //m_size[q].y() = m_size[0].y();
    for (int i = 0;i<=q-1;i++)
    {
        S +=((m_size[i+1].x()-m_size[i].x())*(m_size[i].y()+m_size[i+1].y()))/2;
    }
    return abs(S);
}

int Polygon::SGN(Point p1,Point p2, Point p)
{
    float check = (p.y()-p1.y())*(p2.x()-p1.x())-(p2.y()-p1.y())*(p.x()-p1.x());
    if(check >0)
        return 1;
    if(check<0)
        return -1;
    return 0;
}

bool Polygon::PointOnFig(Point p)
{
    int n = m_size.size();
    int S = SGN(m_size[0],m_size[1],p);
    for (int i=1;i<n-1;i++)
    {
        if (S*SGN(m_size[i],m_size[i+1],p)<0)
            return 0;
    }
    return 1;
}

int Polygon::Convex()
{
    double S = 0.5*((m_size[1].x()-m_size[0].x())*(m_size[2].y()-m_size[0].y())-(m_size[2].x()-m_size[0].x())*(m_size[1].y()-m_size[0].y()));
    for (int i=2; i<m_size.size()-1;i++)
    {
        double s = 0.5 * ((m_size[i].x()-m_size[0].x())*(m_size[i+1].y()-m_size[0].y())-(m_size[i+1].x()-m_size[0].x())*(m_size[i].y()-m_size[0].y()));
        if (S*s<=0)
        {
            return 0;
        }
    }
    return 1;
}


/*double Polygon::OrArea(Point a,Point b, Point c)
{
    double f = 0.5*(b.x()*c.y()+a.x()*b.y()-b.x()*a.y()-c.x()*b.y()-a.x()*c.y()+a.y()*c.x());
    return f;
}

double Polygon::dist (Point p1, Point p2)
{
    return sqrt(pow(p2.x()-p1.x(),2)+pow(p2.y()-p1.y(),2));
}

void Polygon::quick_sort_angle(double angle[], std::vector<double> D_x, std::vector<double> D_y, double di[], int l, int r) {
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

void Polygon::quick_sort_dist(std::vector<double> D_x, std::vector<double> D_y, double di[], int l, int r)
{
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

int Polygon::Graham (std::vector<Point> d)
{
    int n = d.size();
    std::vector<double> D_x={};
    std::vector<double> D_y={};
    for (int i =0; i<=n;i++)
    {
        D_x[i] = d[i].x();
        D_y[i] = d[i].y();
    }
    std::vector<Point> c ={};
    double angle[2020], di[2020];
    double min_x=INT_MAX,min_y=INT_MAX;
    int min_i=INT_MAX;
    for (int i=0;i<n;i++){
        if (D_x[i]<min_x) {min_x=D_x[i]; min_y=D_y[i]; min_i=i;}
        if (D_x[i]==min_x && D_y[i]<min_y) {min_x=D_x[i]; min_y=D_y[i]; min_i=i;}
    }
    std::swap(d[0],d[min_i]);
    for (int i=1; i<n;i++){
        if (D_x[i]-D_x[0]==0) angle[i]=INT_MAX;
        else  angle[i]=(D_y[i]-D_y[0])/(D_x[i]-D_x[0]);
        di[i]=dist(d[i],d[0]);
    }
    quick_sort_angle(angle, D_x, D_y, di,1,n-1);
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

    c[0]=d[0];
    c[1]=d[1];
    c[2]=d[2];

    int m=1;
    for (int i=2;i<=n;i++){
        Point p(D_x[i],D_y[i]);
        while (OrArea(c[m-1],c[m],p)>0)
        {
            m--;
        }
        m++;
        c[m]=p;
    }
    return m;
}*/