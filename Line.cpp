#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Line::Line(Point p1, Point p2) : P1(p1),P2(p2) {}
Line::~Line(){}
Point Line:: Start()
{
    return P1;
}
Point Line:: Finish()
{
    return P2;
}

float Line:: GetLength()
{
    float a = sqrt(pow(P2.x() -P1.x(),2)+pow(P2.y()-P1.y(),2));
    return a;
}
int Line:: SGN(Point p1,Point p2, Point p)
{
    float check = (p.y()-p1.y())*(p2.x()-p1.x())-(p2.y()-p1.y())*(p.x()-p1.x());
    if(check >0)
        return 1;
    if(check<0)
        return -1;
    return 0;
}
int Line:: Intersection(Point p1, Point p2,Point p3, Point p4)
{
    if(SGN(p1,p2,p3)* SGN(p1,p2,p4)<0 && SGN(p3,p4,p1)* SGN(p3,p4,p2)<0)
    {
        std::cout << "segments intersect in ";

        float n;
        if (p2.y() - p1.y() != 0)
        {
            float q = (p2.x() - p1.x()) / (p1.y() - p2.y());
            float sn = (p3.x() - p4.x()) + (p3.y() - p4.y()) * q;
            if (!sn)
                return 0;
            float fn = (p3.x() - p1.x()) + (p3.y() - p1.y()) * q;
            n = fn / sn;
        }
        else
        {
            if (!(p3.y() - p4.y()))
                return 0;
            n = (p3.y() - p1.y()) / (p3.y() - p4.y());
        }
        float a = p3.x() + (p4.x() - p3.x()) * n;
        float b = p3.y() + (p4.y() - p3.y()) * n;
        Point d(a,b);  // точка пересечения
        std::cout << d.x() << " "<< d.y() << std::endl;
        return 1;
    }
    std::cout << "segments don't intersect"<<std::endl;
    return 0;
}

bool Line:: PointOnSegment(float x1,float y1,float x2,float y2,float x,float y)
{
    float check1 = (y-y1)*(x2-x1);
    float check2 = (y2-y1)*(x-x1);
    if(check1==check2 && x >= fmin(x1,x2) && x<= fmax(x1,x2) && y >= fmin(y1,y2) && y <= fmax(y1,y2))
        return 1;
    return 0;
}

void Line::Draw(Line a, Line b)
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        sf::Vertex R[] =
                {
                        sf::Vertex(sf::Vector2f(b.Start().x(), b.Start().y())),
                        sf::Vertex(sf::Vector2f(b.Finish().x(), b.Finish().y()))
                };
        window.draw(R, 2, sf::Lines);
        sf::Vertex RR[] =
                {
                        sf::Vertex(sf::Vector2f(a.Start().x(), a.Start().y())),
                        sf::Vertex(sf::Vector2f(a.Finish().x(), a.Finish().y()))
                };
        window.draw(RR, 2, sf::Lines);
        window.display();
    }
}