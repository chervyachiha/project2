#include <iostream>
#include <vector>
#include "Point.hpp"
#include "Line.hpp"
#include "Fig.hpp"
#include "Graham.hpp"


int main() {
    ///треугольник
    Point tr1(500, 500);
    Point tr2(600, 400);
    Point tr3(400, 100);
    std::vector<Point> v = {tr1, tr2, tr3};
    Triangle f(&v);
    std::cout << "Triangle:" << std::endl;
    std::cout << "Area: " << f.GetArea() << std::endl;
    std::cout << "OrArea: " << f.OrArea() << std::endl;
    f.Draw();
    std::cout<<std::endl;

    ///четырехугольник
    Point p1(900, 100);
    Point p2(700, 700);
    Point p3(300, 200);
    Point p4(500, 100);
    std::vector<Point> v1 = {p2, p3, p4, p1};
    Polygon t(&v1);
    std::cout<< "Quadrangle:" << std::endl;
    std::cout << "Convex: " << t.Convex() << std::endl;
    std::cout << "Area: " << t.GetArea() << std::endl;
    Point l(450, 450);
    std::cout << "Point on figure: " << t.PointOnFig(l) << std::endl;
    t.Draw(l);
    std::cout<<std::endl;

    ///шестиугольник
    Point h1(300, 500);
    Point h2(500, 500);
    Point h3(600, 200);
    Point h4(100, 400);
    Point h5(100, 100);
    Point h6(400, 400);
    std::vector<Point> H = {h1, h2, h3, h6, h5, h4};
    Polygon h(&H);
    std::cout<< "Sexangle:" << std::endl;
    std::cout << "Convex: " << h.Convex() << std::endl;
    std::cout << "Point on figure: " << h.PointOnFig(l) << std::endl;
    h.Draw(l);
    std::cout<<std::endl;


    ///пересекающиеся отрезки
    Point r1(100, 100);
    Point r2(500, 500);
    Point q1(500, 100);
    Point q2(100, 500);
    Line r(r1, r2);
    Line q(q1, q2);
    std::cout << "Lines:"<< std::endl;
    std::cout << "Length: " << r.GetLength() << std::endl;
    r.Intersection(r1, r2, q1, q2);
    r.Draw(r, q);
    std::cout<<std::endl;

    ///грэхем
    Point g1(300, 100);
    Point g2(600, 400);
    Point g3(400, 500);
    Point g4(700, 700);
    Point g5(900, 200);
    Point g6(500, 300);
    Point g7(900, 500);
    Point g8(700, 500);
    Point g9(600, 100);
    Point g10(500, 700);
    Point g11(600, 200);
    std::vector<Point> g = {g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11};
    Graham gr(&g);
    gr.Draw(gr.Gra(g));


    return 0;
}
