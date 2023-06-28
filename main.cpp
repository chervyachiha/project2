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
    sf::Window window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //window.clear();
        //window.draw(shape);
        window.display();
    }

    return 0;
}

/*int main() {
        sf::Window window;
        window.create(sf::VideoMode(640, 480), "SFML Application");
        sf::CircleShape shape;
        shape.setRadius(40.f);
        shape.setPosition(100.f, 100.f);
        shape.setFillColor(sf::Color::Cyan);

        while (window.isOpen())
        {
            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            //window.clear();
            //window.draw(shape);
            window.display();
        }
    }

    sf::RenderWindow window(sf::VideoMode(900, 800), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    Point p1(0,0);
    Point p2(0.25,0.25);
    Point f1(3,0);
    Point f11(1,0);
    Point f2(0,3);
    Point f22(0,1);


    std::vector <Point> v1 ={f1, p2,f2,p1};
    Polygon t(&v1,12,13);


    std::cout << "Convex: " <<t.Convex()<<std::endl;
    std::cout << "Area: " << t.GetArea()<<std::endl;
    Point q(1,1);
    std::cout << "Point on figure: " << t.PointOnFig(q) << std::endl;

    double d_res_x[2020],d_res_y[2020];
    Point g1(2,0);
    Point g2(5,3);
    Point g3(3,4);
    Point g4(6,6);
    Point g5(8,1);
    Point g6(4,2);
    Point g7(8,4);
    Point g8(6,4);
    Point g9(5,0);
    Point g10(4,6);
    Point g11(5,1);
    std::vector<Point> g = {g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11};
    Graham gr(&g);
    std::cout << "Graham: " << gr.Gra(d_res_x,d_res_y) << std::endl;




    Point h1(0,0);
    Point h2(0,3);
    Point h3(2,4);
    Point h4(3,2);
    Point h5(5,1);
    Point h6(0,3);
    std::vector<Point> H = {h3,h4,h5,h6,h1,h2};
    Polygon h(&H,1,1);
    std::cout<<"Convex: " << h.Convex()<<std::endl;

    std::vector <Point> v ={p1,f2,f1};
    Triangle f(&v,12,13);
    if (f.Check()==1)
    {
        std::cout <<"Perimetr: " << f.GetPerimeter() <<std::endl;
        std::cout << "Area: " << f.GetArea() <<std::endl;
        std::cout << "OrArea: " << f.OrArea() <<std::endl;
    }
    Line p(p1,p2);
    Line F(f1,f2);
    std::cout << "Length: " << p.GetLength()<<std::endl;
    std::cout << "Point on segment: " << p.PointOnSegment(0,0,3,3,1,1)<<std::endl;
    p.Intersection(p1,p2,f1,f2);
}*/