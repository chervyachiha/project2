#include "Point.hpp"
#include "Fig.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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
void Triangle::Draw()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i=0; i<m_size.size()-1;i++) {
            sf::Vertex tr[] =
                    {
                            sf::Vertex(sf::Vector2f(m_size[i].x(), m_size[i].y())),
                            sf::Vertex(sf::Vector2f(m_size[i+1].x(), m_size[i+1].y()))
                    };
            window.draw(tr, 2, sf::Lines);
        }
        sf::Vertex tr[] =
                {
                        sf::Vertex(sf::Vector2f(m_size[m_size.size()-1].x(), m_size[m_size.size()-1].y())),
                        sf::Vertex(sf::Vector2f(m_size[0].x(), m_size[0].y()))
                };
        window.draw(tr, 2, sf::Lines);
        window.display();
    }
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

void Polygon::Draw()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i=0; i<m_size.size()-1;i++) {
            sf::Vertex Hh[] =
                    {
                            sf::Vertex(sf::Vector2f(m_size[i].x(), m_size[i].y())),
                            sf::Vertex(sf::Vector2f(m_size[i+1].x(), m_size[i+1].y()))
                    };
            window.draw(Hh, 2, sf::Lines);
        }
        sf::Vertex Hh[] =
                {
                        sf::Vertex(sf::Vector2f(m_size[m_size.size()-1].x(), m_size[m_size.size()-1].y())),
                        sf::Vertex(sf::Vector2f(m_size[0].x(), m_size[0].y()))
                };
        window.draw(Hh, 2, sf::Lines);
        window.display();
    }
}

