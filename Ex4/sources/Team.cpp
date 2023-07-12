#include "Team.hpp"
#include <string.h>
#include <iostream>
#include <set>
using namespace ariel;
using namespace std;

Team::Team(Character* theLeader): leader(theLeader){
    if(theLeader == nullptr){
        throw invalid_argument("leader can not be null");
    }if(theLeader->isLeader() == 1){
        throw std::runtime_error("already leader");
    }else{
        theLeader->isLeader() = 1;
    }
    this->add(theLeader);
}

void Team::add(Character* character){
    if(character == nullptr){
        throw invalid_argument("chacter can not be null");
    }
    if(character->isnTeam() == 1){
        throw std::runtime_error("already in a team");
    }
    if(this->teamCharts.size()<10){
        character->isnTeam() = 1;
        this->teamCharts.insert(character);
    }else{
        throw std::runtime_error("team is full");
    }
}

void Team::attack(Team* otherTeam){
    if(otherTeam == nullptr){
        throw invalid_argument("other team can not be null");
    }
    if(!this->leader->isAlive()){
        
        changeLeader(this->leader);
        
        if(this->leader == nullptr){
            throw invalid_argument("leader can not be null");
        }
    }
    Character* victim = chooseVictim(otherTeam);
    
    if(victim == nullptr){
        throw std::runtime_error("victim can not be null");
    }
    for(Character* ch: this->teamCharts){
        if(!victim->isAlive()){
            victim = chooseVictim(otherTeam);
            if(victim == nullptr){
                return;
            }
        }
        if(ch->getlable() == "C"){
            Cowboy* cb = (Cowboy*)ch;
            if(cb->hasboolets() && cb->isAlive()){
                cb->shoot(victim);
            }else if(cb->isAlive()){
                cb->reload();
            }
        }else if(ch->getlable() == "N"){
            Ninja* ninj = (Ninja*)ch;
            if(ninj->isAlive()){
                if(ninj->distance(victim) < 1){
                    ninj->slash(victim);
                }else{
                 ninj->move(victim);
                }
            }
        }
    }
}

void Team::changeLeader(Character* leader){

    Character* firstelement = *(teamCharts.begin());
    
    while(&leader == &firstelement && !firstelement->isAlive()){
        
        firstelement = *(std::next(teamCharts.begin()));
    }

    double dis = leader->distance(firstelement);
    
    Character* newLeader = firstelement;
    for(Character* ch: teamCharts){
        if(ch->isAlive() && leader->distance(ch) < dis){
            dis = leader->distance(ch);
            newLeader = ch;
        }
    }
    this->leader = newLeader;
    this->leader->isLeader() = 1;
}

Character* Team::chooseVictim(Team* otherTeam){
    double dis = -1;
    Character* firstelement = nullptr;

    if(otherTeam->leader->isAlive()){
        dis = this->leader->distance(otherTeam->leader);
        firstelement = otherTeam->leader;
    }else{
        auto first = otherTeam->teamCharts.begin();
        while(first != otherTeam->teamCharts.end()){
            if ((*first)->isAlive()) {
                firstelement = *first;
                dis = leader->distance(firstelement);
                break;
            }
            ++first;
        }//cheeck if all the team is dead
        if (firstelement == nullptr) {
            return nullptr; // No victim available
        }
    }
    
    Character* victim = firstelement;
    for(Character* ch: otherTeam->teamCharts){
        if(ch->isAlive() && this->leader->distance(ch) < dis){
            dis = this->leader->distance(ch);
            victim = ch;
        }
    }
    return victim;
}
int Team::stillAlive(){
    
    int aliveCharacters = 0;
    for(Character* teamMemb: teamCharts){
        if(teamMemb != nullptr && teamMemb->isAlive()== true){
            aliveCharacters++;
        }
    }
    return aliveCharacters;
   
}
void Team::print(){
    for(Character* teamMemb: teamCharts){
        if(teamMemb != nullptr){
            cout<< teamMemb->print() <<endl;
        }
    }
}

Team::~Team(){
    
}
