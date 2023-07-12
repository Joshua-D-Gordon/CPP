#include "player.hpp"
#include <string>
using namespace ariel;
//Constructors
Player::Player(const char* name){
    this->m_name = name;
    this->stats = new Stats();
    this->m_points = 0;
 
}

Player::Player(){
    this->m_name = "";
    this->stats = new Stats();
    this->m_points = 0;
}
//getter players stack
pstack Player::getPlayerDeck(){
    return this->m_stack; 
}
//increases players hand in deck
void Player::increasePlayerIndex(int index){
    this->m_stack.index += index;  
}
//getter palyers index
int Player::getPlayerIndex(){
    return this->m_stack.index; 
}
//increase players stack size
void Player::increasePlayerSize(int size){
    this->m_stack.size += size; 
}
//getter players name
std::string Player::getPlayerName(){
    return this->m_name;
}
//setter players stack
void Player::setPlayerDeck(Card* cards, int index, int size){
    this->m_stack.cards = cards;
    this->m_stack.index = index;
    this->m_stack.size = size;
}
//getter stack size
int Player::stacksize(){
    return this->m_stack.size;
}
//getter cards taken
int Player::cardesTaken(){
    return this->m_points;
}
//getter palyers stack
pstack Player::getmStack(){
    return this->m_stack;
};
//getter palyer stats
Stats* Player::getStats(){
    return this->stats;
}
//print players stats
void Player::printStats(){
    // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    std::cout<< " win rate is : " << this->stats->WinRate << std::endl;
    std::cout<< "# cards won : " << this->stats->cardsWon << std::endl;
    //other stats added
    std::cout<< "# beat Ace : " << this->stats->beatAce << std::endl;
    std::cout<< "# games ended in draw : " << this->stats->GamesEndedinDraw << std::endl;
    std::cout<< "# turns : " << this->stats->turns << std::endl;
    std::cout<< "# gamesPlayed : " << this->stats->numberOfGamesPlayed << std::endl;

    //draw rate && # draws
    std::cout<< "draw rate : " << this->stats->drawRate << std::endl;
    std::cout<< "# draws : " << this->stats->draws << std::endl;
};




