#pragma once
#include "player.hpp"
#include "card.hpp"
#include "log.hpp"
#include "stats.hpp"
#include <string>

namespace ariel{

class Game{
    private:
        Player *m_p1, *m_p2;
        Card *cardsDeck = nullptr;
        Log *gameLogHead = nullptr, gameLog;
        int gamepotpts;
        int flagEnded;

        void makeDeck();
        void splitDeck(Player *plyr1, Player *plyr2);

    public:
    //constructor
    Game(Player &plyr1, Player &plyr2);
    //getters players
    Player *getP1();
    Player *getP2();
    //getter game log
    Log *getPlog();
    
    //play a turn
    void playTurn();
        //pop pstack of p1 and p2
        //compare cards
        //if winner: push to plog info, increment winner points
        //if draw: push to plog info, double pop stack , try winner
        //if cards all finished and still draw split game pot.
    

    void printLastTurn();
        //prints plog last turn (peek stack)
    

    void playAll();
        //runs play turn untill no more cards
    

    void printWiner();
        //prints winner (player with highest points)
    

    void printLog();
        //prints the log stack in reverse
    

    void printStats();
        //for each player prints basic statistics: 
        //win rate, cards won, <other stats you want to print>. 
        //Also print the draw rate and amount of draws that happand. 
        //(draw within a draw counts as 2 draws. )
    //card comperator
    int compCard(Card card1, Card card2);
    //adds to a log message with comperator, card1, card2
    std::string makeLogMsg(int func, Card card1, Card card2);
    //updates the stats
    void updateStats(int winner, int gamePts, int turns);
    //updates the log
    void updateLog(std::string logstr);

    Card* getCard(){
        return this->cardsDeck;
    }
};
}

