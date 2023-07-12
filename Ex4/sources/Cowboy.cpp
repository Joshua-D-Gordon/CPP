#include "Cowboy.hpp"
#include <string.h>
#include <iostream>
using namespace ariel;

//constructors & deconstructors
Cowboy::Cowboy(string name, Point pnt): Character(pnt, 110, name,"C",0,0,0), boolets(6){
    
}


//getters and setters
int& Cowboy::getBoolets(){
    return this->boolets;
}

//functions
void Cowboy::shoot(Character* other){
    if((this) == other){
        throw std::runtime_error("cant shoot yourself");
    }
    if(!this->isAlive()){
        throw std::runtime_error("character is dead - cb");
    }
    if( this->isAlive() && this->getBoolets() > 0){
        if(!other->isAlive()){
            throw runtime_error("victim already dead - cowboy");
        }else{
            other->getLifepts() -= 10;
            this->getBoolets()--; 
        }
        
    }
}

bool Cowboy::hasboolets(){
    if(this->getBoolets() > 0){
        return true;
    }
    return false;
}
void Cowboy::reload(){
    if(!this->isAlive()){
        throw std::runtime_error("dead cowboy canot reload");
    }
    this->getBoolets() = 6;
}

Cowboy::~Cowboy(){

}