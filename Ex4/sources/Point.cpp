#include "Point.hpp"
#include <cmath>
#include <iostream>
#include <string>

using namespace ariel;

Point::Point(double x_cord, double y_cord){
    this->x = x_cord;
    this->y = y_cord;
}

double Point::distance(Point other) {
    //standard sqrt distance
    return sqrt(pow(this->getX() - other.getX(), 2) + pow(this->getY() - other.getY(),2));
}

void Point::print(){
    std::cout<< "(" << std::to_string(this->x) << "," << std::to_string(this->y) << ")";
}
std::string Point::toString(){
    //returning a string
    return "(" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")";
}
Point Point::moveTowards(Point& pt1, Point& pt2, double distance){
    //cant move negitace distance
    if(distance<0){
        throw std::invalid_argument("cant move negitave distance");
    }
    double pointsDistance=pt1.distance(pt2);
    //if can move to the point return the point
    if(pointsDistance<=distance){
        return pt2;
    }
    //ratio between distance and points distance
    double ratio = distance / pointsDistance;
    //new x and y based on ratio
    double newX = (pt1.x*(1 - ratio)) + (ratio * pt2.x);
    double newY = (pt1.y*(1 - ratio)) + (ratio * pt2.y);
    return Point(newX,newY);
}
double& Point::getX() {
    return this->x;
}
double& Point::getY() {
    return this->y;
}

Point Point::operator+=(Point other){
    return Point::moveTowards((*this), other, 1);
    
}

Point Point::operator/(int speed){
    this->getX()/=speed;
    this->getY()/=speed;
    return (*this);
}

void Point::operator==(Point other){
    this->getX() = other.getX();
    this->getY() = other.getY();
    
}

    
