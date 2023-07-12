#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <chrono>   
#include <thread>
using namespace std;
using namespace ariel;

TEST_CASE("Initilize Game Checks") { // starting cases
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);

    CHECK( p1.cardesTaken() == 0);
    CHECK( p2.cardesTaken() == 0);
    CHECK( p1.stacksize() == 26);
    CHECK( p2.stacksize() == 26);
    CHECK(game.getP1()->getStats()->draws == 0);
    CHECK(game.getP1()->getStats()->turns == 0);
    CHECK(game.getP1()->getStats()->drawRate == 0);
    CHECK(game.getP1()->getStats()->beatAce == 0);
    CHECK(game.getP1()->getStats()->WinRate == 0);
    CHECK(game.getP1()->getStats()->cardsWon == 0);
}

TEST_CASE("One player per game") { // one player per game test
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);
    Player p3("intruder");
    CHECK_THROWS(Game(p1,p3));
    CHECK_THROWS(Game(p3,p2));
    CHECK_THROWS(Game(p1,p2));
}

TEST_CASE("Shuffel test") { // starting cases shuffeled deck  - "fairness test" - "95%"
    //note this dose not represent a acctual shuffle check but rather a fairness check that each player has an eqaul chance of winning any given game
    double PoneWins = 0;
    double epsilon = 0.05, delta = 0.05, p = 1/2;
    int nbase = ((1)/2*(epsilon*epsilon)*(delta));
    nbase+=1; // n > 1/2*epsilon^2 * delta
    //based on chebyshev's inequality - הסתברות 2 הרצאה 1
    Player ps1("one");
    Player ps2("Two");
    for(int i = 0; i<nbase; i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Game games(ps1, ps2);
        games.playAll();
        if(games.getP1()->cardesTaken() > games.getP2()->cardesTaken()){
            PoneWins+=1;
        }
        ps1.setPlayerDeck(nullptr,0,0);
        ps2.setPlayerDeck(nullptr,0,0);
    }
    double q = PoneWins/nbase;

    double absPQ = 0;
    if((q-p)<0){
        absPQ = p - q;
    }else{
        absPQ = q - p;
    }
    CHECK(absPQ < epsilon); // 95% accuracy --> 1- delta
}

TEST_CASE("Initilize Game Checks") { // starting cases for functions
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
}


TEST_CASE("Check after turn") { // after turn case
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);
    game.playTurn();

    CHECK( p1.cardesTaken() + p2.cardesTaken() > 0);
    CHECK( p1.stacksize() < 26);
    CHECK( p2.stacksize() < 26);
    CHECK(game.getP1()->getStats()->draws >= 0);
    CHECK(game.getP1()->cardesTaken() + game.getP2()->cardesTaken() == p1.cardesTaken() + p2.cardesTaken());
    CHECK(game.getP1()->getStats()->turns == 1);
    CHECK(game.getP2()->getStats()->turns == 1);


    
    if(game.getP1()->cardesTaken() + game.getP2()->cardesTaken() != 52){ // game has not ended
    
        CHECK_NOTHROW(game.printWiner());
    }
    
    
}

TEST_CASE("Check end game") { // after end game case's
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);

    game.playAll();
    CHECK( p1.cardesTaken() + p2.cardesTaken() == 52);
    if(game.getP1()->getStats()->WinRate == game.getP2()->getStats()->WinRate){
        CHECK_NOTHROW(game.printWiner());
        CHECK(game.getP1()->getStats()->cardsWon == game.getP2()->getStats()->cardsWon);
    }
    
    CHECK(game.getP1()->getmStack().size == 0);
    CHECK(game.getP2()->getmStack().size == 0);
    
    CHECK(game.getP1()->getStats()->turns >= 1);
    
    CHECK(game.getP1()->getStats()->cardsWon + game.getP2()->getStats()->cardsWon >= 0);
    
}


TEST_CASE("The card scheme at the end of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    int sum = p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken();
    CHECK(sum == 52);
}

TEST_CASE("Throwing errors from the functions")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        game.playTurn();
    }
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Activating another turn after the game is over")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("One player")
{
    Player p1("Alice");
    Game game(p1, p1);
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Printing the winner")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    if (p1.cardesTaken() == p2.cardesTaken())
    {
        CHECK_THROWS(game.printWiner());
    }
    else
    {
        CHECK_NOTHROW(game.printWiner());
    }
}