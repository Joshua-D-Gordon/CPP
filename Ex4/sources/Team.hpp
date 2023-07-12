#pragma once
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <set>



namespace ariel{
class Comparator{
    public:
         bool operator()( Character* c1, Character* c2) const {
            if (c1->getlable() == "C" && c2->getlable() == "N") {
                return true;  // c1 is cowboy, c2 is ninja
            } else if (c1->getlable() == "N" &&c2->getlable() == "C") {
                return false; // c1 is ninja, c2 is cowboy
            } 
            return true;
    }    
};

class Team{
    public:
        Character* leader;
        set<Character*, Comparator> teamCharts;
    
        
        Team(Character* theLeader);
        
        ~Team();

        void add(Character* character);
        void attack(Team* otherTeam);
        int stillAlive();
        void print();

        void changeLeader(Character* leader);
        
        Character* chooseVictim(Team*);
        void CowboysFirenReload(Character*);
        void NinjasSlashnMove(Character*);
        bool victimAlive(Character*);
        
};
}
