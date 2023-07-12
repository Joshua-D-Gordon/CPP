#pragma once
#include "Point.hpp"
#include <string>

namespace ariel{
using namespace std;
//character
class Character{
    private:
    
        Point location;
        int lifepts;
        string name;
        //C or N for cowboy or Ninja
        string label;
        //flag for is leader
        int isleader;
        //flag for is in team
        int isInTeam;
        
    public:
    //distance to sometarget
    int dtv;
    //constructors & deconstructors
    Character(): location(Point(0,0)), lifepts(0), name(""),label(""),isleader(0),isInTeam(0), dtv(0){}
    Character(Point loc, int lifeptsAmount, string charcatersName, string lab, int isl, int ist, int dtv);

    //virtual functions for dynamic overloading at runtime
    virtual ~Character();
    //getters & setters
    virtual Point& getLocation();
    virtual int& getLifepts();
    virtual std::string& getName();
    virtual std::string& getlable();
    virtual int& isLeader();
    virtual int& isnTeam();


    virtual bool isAlive(); // if lifepts>0 true
    virtual double distance(Character* otherCharacter);
    virtual void hit(int num);
    virtual std::string print();
};
}