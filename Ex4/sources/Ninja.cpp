#include "Ninja.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Ninja::Ninja(Point loc, int lifepts, string name, int speed):Character(loc,lifepts,name,"N",0,0,0), speed(speed), slashpts(40){

}
void Ninja::move(Character* other){
    this->getLocation() = Point::moveTowards(this->getLocation(),other->getLocation(),this->getSpeed()); 
}
void Ninja::slash(Character* other){
    if((this) == other){
        throw std::runtime_error("cant slash yourself");
    }
    if(!this->isAlive()){
        throw runtime_error("character is dead - n");
    }
    if(this->isAlive() && this->getLocation().distance(other->getLocation()) < 1){
        if(!other->isAlive()){
            throw std::runtime_error("victim already dead - ninja");
        }else{
            other->getLifepts()-=this->getSlashpts();
        }
        //other->getLifepts()-=this->getSlashpts();
    }
}
int Ninja::getSpeed(){
    return this->speed;
}
int Ninja::getSlashpts(){
    return this->slashpts;
}