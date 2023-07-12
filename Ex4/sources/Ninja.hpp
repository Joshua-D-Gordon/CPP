#pragma once

#include "Character.hpp"

namespace ariel{
class Ninja: public Character{
    private:
        int speed;
        int slashpts;
    public:
        Ninja(Point loc, int lifepts, std::string name, int speed);
        //virtual functions for dynamic overloading at runtime
        virtual void move(Character*);
        virtual void slash(Character*);
        virtual int getSpeed();
        virtual int getSlashpts();
        
};
}