#pragma once
#include "card.hpp"
#include "stats.hpp"
#include <string>
#include <iostream>

namespace ariel{
//players stack of cards
typedef struct pstack
{
    int size = 0, index = 0;
    Card *cards = nullptr;

}pstack;


class Player{

    private:
        const char* m_name;
        int m_points;
        Stats *stats;
        pstack m_stack;
    public:
    //constructors
    Player();
    Player(const char* m_name);
    //set players deck
    void setPlayerDeck(Card* cards, int index, int size);
    //move players hand in cards deck
    void increasePlayerIndex(int index);
    //decrease players deck size
    void increasePlayerSize(int size);
    //setter players points
    void setmPoints(int pts){
        this->m_points = pts;
    }
    //adding points to player
    void addmPoints(int pts){
        this->m_points+=pts;
    }
    //getter players deck
    pstack getPlayerDeck();
    //getter playyers index
    int getPlayerIndex();
    //getter players name
    std::string getPlayerName();
    //players stacksize
    int stacksize();
    //players cardes taken
    int cardesTaken();
    //printing players stats
    void printStats();
    //get players stack
    pstack getmStack();
    //getter palyers stats
    Stats * getStats();

};
}