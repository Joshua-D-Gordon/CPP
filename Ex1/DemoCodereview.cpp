#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <chrono>   
#include <thread>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

Player tourner(Player ply1, Player ply2){
  std::this_thread::sleep_for(std::chrono::seconds(1));
  Game game(ply1,ply2);
  game.playAll();
  cout<<game.getP1()->getPlayerName()<< " cards taken :"<<game.getP1()->cardesTaken()<<" "<<game.getP2()->getPlayerName()<< " cards taken :"<<game.getP2()->cardesTaken()<<endl;
  if(game.getP1()->cardesTaken() == game.getP2()->cardesTaken()){
    cout<<"redo"<<endl;
    ply1.setPlayerDeck(nullptr,0,0);
    ply2.setPlayerDeck(nullptr,0,0);
    return tourner(ply1,ply2);
  }
  if(game.getP1()->cardesTaken() > game.getP2()->cardesTaken()){
    ply1.setPlayerDeck(nullptr,0,0);
    ply2.setPlayerDeck(nullptr,0,0);
    return ply1;
  }else{
    ply1.setPlayerDeck(nullptr,0,0);
    ply2.setPlayerDeck(nullptr,0,0);
    return ply2;
  }

}
int main() {
  cout << "****************************DEMO***************************************" << endl;
  cout << "***********************************************************************\n" << endl;
  cout << "****************************Cards**************************************"<<endl;
  Card c1(ACE, DIAMONDS);
  cout<<"The card is : " << c1.to_string()<<endl;
  cout<<"The card values are : " << c1.getIntValue() << ", "<< c1.getS()<<"\n"<<endl;

  Card c2(TWO, SPADES);
  Card c3(NINE, HEARTS);
  cout<<"card2 is : " << c2.to_string() << " and card3 is : " << c3.to_string()<<endl;
  cout<<"The cards values are : " << c2.getIntValue() << ", "<< c2.getS()<<" and "<< c3.getIntValue() << ", "<< c3.getS()<<"\n"<<endl;
  Card c4(NINE,SPADES);
  int ans = Card::comp(c2,c3);
  cout<<"comparing "<<c2.to_string()<<" and " <<c3.to_string() << " = "<<ans<<endl;
  ans = Card::comp(c2,c1);
  cout<<"comparing "<<c2.to_string()<<" and " <<c1.to_string() << " = "<<ans<<endl;
  ans = Card::comp(c3,c4);
  cout<<"comparing "<<c3.to_string()<<" and " <<c4.to_string() << " = "<<ans<<"\n"<<endl;
  
  
  cout<<"****************************Players**************************************"<<endl;
  cout<<"creating 8 Players"<<endl;
  // Create two players with their names 
  Player p1("Joshua");
  Player p2("Gavriel");
  Player p3("Brandon");
  Player p4("Doron");
  Player p5("Mike");
  Player p6("Wendy");
  Player p7("kanye");
  Player p8("Sophie");
  cout<<"The 8 players are: "<<p1.getPlayerName() + ", " + p2.getPlayerName()+ ", " + p3.getPlayerName()+ ", " + p4.getPlayerName()+ ", " + p5.getPlayerName()+ ", " + p6.getPlayerName()+ ", " + p7.getPlayerName()+ ", " + p8.getPlayerName()<<"\n"<<endl;

  cout<<"Player Functions:"<<endl;
  cout<<p1.getPlayerName()<<" cards taken : "<< p1.cardesTaken()<<endl;
  cout<<"printing "<<p1.getPlayerName()<<" stats:"<<endl;
  p1.printStats();
  cout<<p1.getPlayerName()<<" stack size: "<<p1.getmStack().size<<endl;
  cout<<p1.getPlayerName()<<" stack index: "<<p1.getmStack().index<<"\n"<<endl;

  cout<<"****************************Game**************************************"<<endl;
  cout<<"creating game with player pOne and player pTwo"<<endl;
  Player pOne("p1");
  Player pTwo("p2");
  Game game(pOne,pTwo);
  cout<<"Game palyers are: "<< game.getP1()->getPlayerName() + ", " + game.getP2()->getPlayerName()<<endl;
  cout<<"Game comparing cards: "<<c1.to_string() + ", "+ c2.to_string()<<" = "<< game.compCard(c1,c2)<<endl;
  cout<<"Game comparing cards: "<<c2.to_string() + ", "+ c3.to_string()<<" = "<< game.compCard(c2,c3)<<endl;
  cout<<"Game comparing cards: "<<c3.to_string() + ", "+ c3.to_string()<<" = "<< game.compCard(c3,c3)<<"\n"<<endl;

  cout<<"playing a turn then printing last turn:"<<endl;
  game.playTurn();
  game.printLastTurn();
  cout<<"\n"<<"playing 4 turns then printing game log (5 turns total): "<<endl;
  for(int j = 0; j<5; j++){
    game.playTurn();
  }
  game.printLog();

  cout<<"\n"<<"****************************Tounment**************************************"<<endl;
  Player winner;
  for(int i = 0; i< 4; i++){
    winner = tourner((tourner(p1,p2),tourner(p3,p4)),(tourner(p5,p6),tourner(p7,p8)));
    cout<<"Winner of Touner "<<i<<" is: "<< winner.getPlayerName()<<endl;
    if(i == 3){
      cout<<"printing players stats\n"<<endl;
      Game gamestats1(p1,p2);
      gamestats1.printStats();
      
      Game gamestats2(p3,p4);
      gamestats2.printStats();
      
      Game gamestats3(p5,p6);
      gamestats3.printStats();
      
      Game gamestats4(p7,p8);
      gamestats4.printStats();
      
    }
  }
  cout<<"\n\n"<<"****************************New Game**************************************"<<endl;
  cout<<"new game"<<endl;
  p1.setPlayerDeck(nullptr,0,0);
  p2.setPlayerDeck(nullptr,0,0);
  Game game1(p1,p2);
  cout<<"playing 10 turns"<<endl;
  for (int i=0;i<10;i++) {
    game1.playTurn();
  }
  game1.printLastTurn(); // print the last turn stats. For example:
  cout <<p1.getPlayerName()<<" stack size is: "<< p1.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
  cout <<p2.getPlayerName()<<" # cards taken: "<< p2.cardesTaken() << endl; // prints the amount of cards this player has won. 
  game1.playAll(); //playes the game untill the end
  cout<<"game winner is: "<<endl;
  game1.printWiner(); // prints the name of the winning player
  cout<<"printing gamelog"<<endl;
  game1.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
  cout<<"printing players stats: "<<endl;
  game1.printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

}