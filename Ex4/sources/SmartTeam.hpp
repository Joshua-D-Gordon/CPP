#pragma once
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"


#include <set>
#include <vector>

#include "Team2.hpp"

namespace ariel{
class SmartComparator{
    public:
        Character* vic;
        void setvic(Character* vic){
            this->vic = vic;
        }
        
         bool operator()( Character* c1, Character* c2) const {
            if (c1->getlable() == "C" && c2->getlable() == "N") {
                return true;  // c1 is cowboy, c2 is ninja
            } else if (c1->getlable() == "N" &&c2->getlable() == "C") {
                return false; // c1 is ninja, c2 is cowboy
            } else if (c1->getlable() == "C" &&c2->getlable() == "C")
            {
                return true;
            }else{
                //ninjas closer go first
                if(c1->dtv <= c2->dtv){
                    return true;
                }
                return false;
            }
            
            return true;
    }    
};

class SmartTeam{
    public:
        Character* leader;
        set<Character*, SmartComparator> teamCharts;
        set<Character*, SmartComparator> cpy;
    
        
        SmartTeam(Character* theLeader);
        
        ~SmartTeam();

        void add(Character* character);
        //add to copy
        void attack(Team* otherTeam);
        //void attack(Team2* otherTeam);
        void attack(SmartTeam* otherTeams);
        //SmartTeam
        int stillAlive();
        void print();

        void changeLeader(Character* leader);
        
        Character* chooseVictim(Team*);
        //Character* chooseVictim(Team2*);
        Character* chooseVictim(SmartTeam*);
        
        void CowboysFirenReload(Character*);
        void NinjasSlashnMove(Character*);
        bool victimAlive(Character*);

        //before attacks
        void reorderSet() {
            teamCharts.clear();  // Clear the existing set
    
            for (auto character : cpy) {
                teamCharts.insert(character);  // Insert elements from the new set
            }
        }
        
};
}
