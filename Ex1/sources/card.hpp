#pragma once
#include <iostream>
#include <string>

namespace ariel{
//Card Enum values number & symbol
typedef enum val{
    ACE=1, TWO, THREE ,FOUR, FIVE ,SIX, SEVEN , EIGHT, NINE, TEN, JACK, QUEEN, KING, LASTVAL                   
}val;
typedef enum symb{
    CLUBS = 1, DIAMONDS, HEARTS, SPADES, LASTSYMB
}symb;

class Card{
    private:
        val m_value;
        symb m_symbol;

    public:
    //constructors
    Card();
    Card(val val, symb symb);
    //setter
    void setCard(val m_val, symb m_symb);
    //getters values and ints
    val getVal();

    int getIntValue() const;
    
    int getS();

    symb getSymb();
    //comparator
    static int comp(Card card1, Card card2);
    //to string
    std::string to_string();
};

}