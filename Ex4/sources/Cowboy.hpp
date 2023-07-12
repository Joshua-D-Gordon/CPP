#pragma once
#include "Character.hpp"

namespace ariel{
class Cowboy : public Character
{
private:
    int boolets;
public:
    //constructors & deconstructors
    //Cowboy(Point loc, int lifepts, std::string name, int bullets);
    Cowboy(std::string name, Point pnt);
    ~Cowboy();

    //getters and setters
    int& getBoolets();

    //functions
    void shoot(Character*);

    bool hasboolets();
    void reload();
};
}
