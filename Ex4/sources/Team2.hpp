#pragma once
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "SmartTeam.hpp"
#include <set>



namespace ariel{
class Comparator2{
    public:
         bool operator()( Character* c1, Character* c2) const {
            //no order
            return true;
    }    
};

class Team2{
    public:
        Character* leader;
        set<Character*, Comparator2> teamCharts;
    
        
        Team2(Character* theLeader);
        
        ~Team2();

        void add(Character* character);
        void attack(Team* otherTeam);
        void attack(Team2* otherTeam2);
        void attack(SmartTeam* otherTeam2);
        void attack(std::nullptr_t);
        int stillAlive();
        void print();

        void changeLeader(Character* leader);
        
        Character* chooseVictim(Team*);
        Character* chooseVictim(Team2*);
        Character* chooseVictim(SmartTeam*);
        void CowboysFirenReload(Character*);
        void NinjasSlashnMove(Character*);
        bool victimAlive(Character*);
        
};
}
