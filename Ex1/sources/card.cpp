#include "card.hpp"

using namespace ariel;
//default constructor
Card::Card(){
    this->m_value = LASTVAL;
    this->m_symbol = LASTSYMB;
}
//constructor
Card::Card(val v, symb s){
    this->m_value = v;
    this->m_symbol = s;
}
//setter
void Card::setCard(val m_v, symb m_s){
    this->m_value = m_v;
    this->m_symbol = m_s;
};
//getter value
val Card::getVal(){return m_value;}
//getter value int
int Card::getIntValue() const {
    int intValue = static_cast<int>(m_value);
    
    return intValue;
   
} 
//getter symbol int
int Card::getS(){
    return (symb)this->m_symbol;
    
}
//getter symbol
symb Card::getSymb(){
    return m_symbol;
}
//to string of card
std::string Card::to_string() {
    std::string numberStr;
    switch(m_value) {
        case ACE: numberStr = "Ace"; break;
        case TWO: numberStr = "Two"; break;
        case THREE: numberStr = "Three"; break;
        case FOUR: numberStr = "Four"; break;
        case FIVE: numberStr = "Five"; break;
        case SIX: numberStr = "Six"; break;
        case SEVEN: numberStr = "Seven"; break;
        case EIGHT: numberStr = "Eight"; break;
        case NINE: numberStr = "Nine"; break;
        case TEN: numberStr = "Ten"; break;
        case JACK: numberStr = "Jack"; break;
        case QUEEN: numberStr = "Queen"; break;
        case KING: numberStr = "King"; break;
        default: numberStr = "Unknown Number"; break;
    }

    std::string symbolStr;
    switch(m_symbol) {
        case CLUBS: symbolStr = "Clubs"; break;
        case DIAMONDS: symbolStr = "Diamonds"; break;
        case HEARTS: symbolStr = "Hearts"; break;
        case SPADES: symbolStr = "Spades"; break;
        default: symbolStr = "Unknown Symbol"; break;
    }

    return numberStr + " of " + symbolStr;
    
}
//comparator 
int Card::comp(Card c1, Card c2){
    //draw
    if(c1.getVal() == c2.getVal()){
        return 0;
    }
    //ace && two cases
    if(c1.getIntValue() == 1 && c2.getIntValue() == 2){
        return -1;
    }
    if(c2.getIntValue() == 1 && c1.getIntValue() == 2){
        return 1;
    }
    //ace cases
    if(c1.getIntValue() == 1){
        return 1;
    }
    if(c2.getIntValue() == 1){
        return 1;
    }
    //normal cases
    if(c1.getVal()>c2.getVal()){
        return 1;
    }else{
        return -1;
    }
    
} 