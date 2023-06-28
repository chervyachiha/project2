#include <iostream>
#include <vector>
#include "Point.hpp"
#include "Line.hpp"
#include "Fig.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>
#include "Graham.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(2580, 1500), "SFML works!");

    ///треугольник
    Point tr1(1500,500);
    Point tr2(1600,400);
    Point tr3(1400,100);
    std::vector <Point> v ={tr1,tr2,tr3};
    Triangle f(&v);
    std::cout <<"Perimetr: " << f.GetPerimeter() <<std::endl;
    std::cout << "Area: " << f.GetArea() <<std::endl;
    std::cout << "OrArea: " << f.OrArea() <<std::endl;

    ///четырехугольник
    Point p1(2000,600);
    Point p2(2000,1200);
    Point p3(2100,700);
    Point p4(2500, 600);
    std::vector <Point> v1 ={p2,p3,p4,p1};
    Polygon t(&v1);
    std::cout << "Convex: " <<t.Convex()<<std::endl;
    std::cout << "Area: " << t.GetArea()<<std::endl;
    Point l(450,450);
    std::cout << "Point on figure: " << t.PointOnFig(l) << std::endl;

    ///шестиугольник
    Point h1(300,1200);
    Point h2(500,1200);
    Point h3(600,900);
    Point h4(100,1100);
    Point h5(100,800);
    Point h6(100,1100);
    std::vector<Point> H = {h1,h2,h3,h4,h5,h6};
    Polygon h(&H);
    std::cout<<"Convex: " << h.Convex()<<std::endl;

    ///грэхем
    double c_x[2020], c_y[2020];
    std::vector<Point> c = {};
    Point g1(300,100);
    Point g2(600,400);
    Point g3(400,500);
    Point g4(700,700);
    Point g5(900,200);
    Point g6(500,300);
    Point g7(900,500);
    Point g8(700,500);
    Point g9(600,100);
    Point g10(500,700);
    Point g11(600,200);
    std::vector<Point> g = {g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11};
    Graham gr(&g);
    gr.Gra(c_x,c_y,c);


    ///пересекающиеся отрезки
    Point r1(1100,1100);
    Point r2(1400,1400);
    Point q1(1000,1400);
    Point q2(1500,900);
    Line r(r1,r2);
    Line q(q1,q2);
    std::cout << "Length: " << r.GetLength()<<std::endl;
    r.Intersection(r1,r2,q1,q2);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();



        /*Point h1(300,500);
        Point h2(400,300);
        Point h3(600,200);
        Point h4(100,400);
        Point h5(100,100);
        Point h6(100,400);
        std::vector<Point> H = {h1,h2,h3,h4,h5,h6};*/
        ///шестиугольник
        H.push_back(H[0]);
        for (int i=0; i<H.size()-1;i++) {
            sf::Vertex Hh[] =
                    {
                            sf::Vertex(sf::Vector2f(H[i].x(), H[i].y())),
                            sf::Vertex(sf::Vector2f(H[i+1].x(), H[i+1].y()))
                    };
            window.draw(Hh, 2, sf::Lines);
        }

        ///грэхем
        for (int i=0;i<g.size();i++) {
            sf::CircleShape gg(5);
            gg.setFillColor(sf::Color::Green);
            gg.setPosition(g[i].x(), g[i].y());
            window.draw(gg);
        }
        /*c.push_back(c[0]);
        for (int i=0; i<c.size()-1;i++) {
            sf::Vertex yy[] =
                    {
                            sf::Vertex(sf::Vector2f(c[i].x(), c[i].y())),
                            sf::Vertex(sf::Vector2f(c[i+1].x(), c[i+1].y()))
                    };
            window.draw(yy, 2, sf::Lines);
        }*/


        ///треугольник
        v.push_back(v[0]);
        for (int i=0; i<v.size()-1;i++) {
            sf::Vertex tr[] =
                    {
                            sf::Vertex(sf::Vector2f(v[i].x(), v[i].y())),
                            sf::Vertex(sf::Vector2f(v[i+1].x(), v[i+1].y()))
                    };
            window.draw(tr, 2, sf::Lines);
        }

        ///четырехугольник
        v1.push_back(v1[0]);
        for (int i=0; i<v1.size()-1;i++) {
            sf::Vertex tr[] =
                    {
                            sf::Vertex(sf::Vector2f(v1[i].x(), v1[i].y())),
                            sf::Vertex(sf::Vector2f(v1[i+1].x(), v1[i+1].y()))
                    };
            window.draw(tr, 2, sf::Lines);
        }

        ///пересекающиеся отрезки
        sf::Vertex R[] =
                {
                        sf::Vertex(sf::Vector2f(r1.x(), r1.y())),
                        sf::Vertex(sf::Vector2f(r2.x(), r2.y()))
                };

        sf::Vertex Q[] =
                {
                        sf::Vertex(sf::Vector2f(q1.x(), q1.y())),
                        sf::Vertex(sf::Vector2f(q2.x(), q2.y()))
                };
        window.draw(Q, 2, sf::Lines);
        window.draw(R, 2, sf::Lines);


        window.display();
    }
return 0;
}