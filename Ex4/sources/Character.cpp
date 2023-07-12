#include "Character.hpp"
#include <string.h>
#include <iostream>
#include "Point.hpp"
using namespace ariel;
using namespace std;
    Character::Character(Point loc, int lifepts, string name, string lab, int isl, int ist, int dtv):location(loc), lifepts(lifepts), name(name), label(lab), isleader(isl), isInTeam(ist), dtv(dtv){

    }
    //getters & setters
    Point& Character::getLocation(){
        return this->location;
    }
    int& Character::getLifepts(){
        return this->lifepts;
    }
    int& Character::isLeader(){
        return this->isleader;
    }
    int& Character::isnTeam(){
        return this->isInTeam;
    }
    string& Character::getName(){
        return this->name;
    }
    string& Character::getlable(){
        return this->label;
    }
    //if lifepts > 0 alive else dead
    bool Character::isAlive(){
        if(this->getLifepts()>0){
            return true;
        }
        return false;
    }
    //return distance based on location
    double Character::distance(Character* c){
        return this->getLocation().distance(c->getLocation());
    }
    //reduct lifepts
    void Character::hit(int num){
        if(num<0){
            throw std::invalid_argument("num cant be negitave");
        }
        this->getLifepts() -= num;
    }
    //to string
    std::string Character::print(){
        return this->getName() + " , " + std::to_string(this->getLifepts()) + " , " + this->getLocation().toString();
    }

   Character::~Character(){

   }