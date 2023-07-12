#pragma once
#include <string>
namespace ariel{

class Point{
    private:
        //points cords
        double x, y;
    public:
        //constructors
        Point(): x(0), y(0){}

        Point(double x_cord, double y_cord);
        //getters & setters
        double& getX();
        double& getY();
        //other functions
        double distance(Point);

        void print();

        static Point moveTowards(Point&, Point&, double distance);

        //for adding points
        Point operator+=(Point);
        //for normalizng points
        Point operator/(int);
        
        void operator==(Point);
        std::string toString();
};
}