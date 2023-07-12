#include "game.hpp"
#include <cstdlib>
#include <string>
using namespace ariel;

//constructor
Game::Game(Player &p1, Player &p2){
    if(p1.getmStack().cards != nullptr ){
        throw(std::invalid_argument("player already playing"));
    }
    if(p2.getmStack().cards !=nullptr){
        throw(std::invalid_argument("player already playing"));
    }
    this->m_p1 = &p1;
    this->m_p2 = &p2;
    //make new deck
    this->makeDeck();
    //split deck between player 1 and player 2
    this->splitDeck(m_p1, m_p2);
    //new game log
    this->gameLogHead = new Log();
    
    this->gamepotpts = 0;
    this->flagEnded = 0;
}
//make 52 deck of shuffeled cards
void Game::makeDeck(){
        Card* cards = new Card[52];
        
        this->cardsDeck = &cards[0];
        int i=0;
        for(int k = ACE; k!=LASTVAL; k++){
                for(int j = CLUBS; j!=LASTSYMB; j++){

                        cards[i].setCard(static_cast<val>(k), static_cast<symb>(j));
                        i++;
                }
        }

        //from chatGPT so we dont keep getting the same result
        srand(time(0));
        //from geeks.com for shuffeling an array
        for (int i=0; i<52 ;i++){
                 //Random for remaining positions.
                int r = i + (rand() % (52 -i));
 
                std::swap(cards[i], cards[r]);
        }

}
//spliting the deck for players
void Game::splitDeck(Player *plyr1, Player *plyr2){
        //set players pile of cards
        m_p1->setPlayerDeck(this->cardsDeck,0,26);
        m_p2->setPlayerDeck(this->cardsDeck,51,26);
        //set players points
        m_p1->setmPoints(0);
        m_p2->setmPoints(0);
        //updating stats
        getP1()->getStats()->numberOfGamesPlayed++;
        getP2()->getStats()->numberOfGamesPlayed++;
}
//getters players
Player* Game::getP1(){
        return this->m_p1; 
}
Player* Game::getP2(){
        return this->m_p2; 
}
//make log message function
std::string Game::makeLogMsg(int func, Card c1, Card c2){
        //starting emepty string
        std::string Str = "";
        //add draw to string
        if(func == 0){
                Str += m_p1->getPlayerName() + " played " + c1.to_string() + " " + m_p2->getPlayerName() + " played " + c2.to_string()+". draw. ";
        //add player1 wins        
        }else if(func == 1){
                Str += m_p1->getPlayerName() + " played " + c1.to_string() + " " + m_p2->getPlayerName() + " played " + c2.to_string()+". "+m_p1->getPlayerName() +" Wins.";
        //add player2 wins        
        }else{
                Str += m_p1->getPlayerName() + " played " + c1.to_string() + " " + m_p2->getPlayerName() + " played " + c2.to_string()+". "+m_p2->getPlayerName() +" Wins.";
        }
        return Str;
        
        
}

void Game::updateLog(std::string logstr){
        //temp log runner       
        Log* gameLogTemp = gameLogHead;
        //get to last log
        while(gameLogTemp->next != nullptr){
                gameLogTemp = gameLogTemp->next;
        }
        //add new log string to log
        gameLogTemp->next = new Log(logstr);
};
//update game stats
void Game::updateStats(int winner, int gamePts, int turns){
        //add turns played
        getP1()->getStats()->turns+=turns;
        getP2()->getStats()->turns+=turns;
        //add players gamepts to cards won
        if(winner == 1){
                getP1()->getStats()->cardsWon+=gamePts;
        }else{
                getP2()->getStats()->cardsWon+=gamePts;
        }
        
}
//playing a game turn
void Game::playTurn(){
        //throw for cases if game has already ended
        if(this->flagEnded==1){
                throw(std::invalid_argument("Game has already ended"));
        }
        //if player is te same player
        if(getP1() == getP2()){
                throw(std::invalid_argument("Cant play against yourself"));
        }
        //pop pstack of p1 and p2 as cards c1 and c2
        Card c1, c2;
        c1 = m_p1->getPlayerDeck().cards[m_p1->getPlayerIndex()];
        c2 = m_p2->getPlayerDeck().cards[m_p2->getPlayerIndex()];

        //start new log string
        std::string logStr = "";

        //while there is a draw and cards in players deck > 2
        while(compCard(c1, c2) == 0 && m_p2->getPlayerDeck().size > 2){
                //add to log string data of cards
                logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                //move players card index
                m_p1->increasePlayerIndex(2);
                m_p2->increasePlayerIndex(-2);
                //decrease players size
                m_p1->increasePlayerSize(-2);
                m_p2->increasePlayerSize(-2);
                //draw new card for each player
                c1 = m_p1->getPlayerDeck().cards[m_p1->getPlayerDeck().index];
                c2 = m_p2->getPlayerDeck().cards[m_p2->getPlayerDeck().index];
                //add 4 to the game pot
                this->gamepotpts += 4;
                //updating player stats
                getP1()->getStats()->draws++;
                getP2()->getStats()->draws++;
        }
        //if players are on therelast two cards or less
        if(m_p2->getPlayerDeck().size == 2 || m_p2->getPlayerDeck().size == 1 || m_p2->getPlayerDeck().size == 0){
                //draw case
                if(compCard(c1,c2)==0){
                        //add to log string
                        logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                        //updating player stats
                        getP1()->getStats()->draws++;
                        getP2()->getStats()->draws++;
                        getP1()->getStats()->cardsWon++;
                        getP2()->getStats()->cardsWon++;
                        getP1()->getStats()->GamesEndedinDraw++;
                        getP2()->getStats()->GamesEndedinDraw++;
                        //ending the game
                        if(m_p2->getPlayerDeck().size == 2){
                                m_p1->addmPoints(2);
                                m_p2->addmPoints(2);
                        }else if(m_p2->getPlayerDeck().size == 1){
                                m_p1->addmPoints(1);
                                m_p2->addmPoints(1);
                        }
                //if player 1 wins
                }else if(compCard(c1,c2)==1){
                        //add to log string
                        logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                        this->gamepotpts+=2;
                        m_p1->addmPoints(gamepotpts);
                //if player 2 wins
                }else{
                        //add to log string
                        logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                        this->gamepotpts+=2;
                        m_p2->addmPoints(gamepotpts);
                }
                //moveplayers hand on card deck to next card and decrase size.
                m_p1->increasePlayerIndex(1);
                m_p2->increasePlayerIndex(-1);
                m_p1->increasePlayerSize(-1);
                m_p2->increasePlayerSize(-1);
                //update player stats
                updateStats(compCard(c1,c2), gamepotpts, 1);
                this->gamepotpts = 0;
                if(m_p2->getPlayerDeck().size != 1){
                        this->flagEnded = 1;        
                }
                
                //update log
                updateLog(logStr);
                
                return;
        }
        
        //moveplayers hand on card deck to next card and decrase size.
        m_p1->increasePlayerIndex(1);
        m_p2->increasePlayerIndex(-1);
        m_p1->increasePlayerSize(-1);
        m_p2->increasePlayerSize(-1);
        //add game points
        this->gamepotpts += 2;

        //if player 1 wins
        if(compCard(c1,c2 )==1){
                //update log and add points
                logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                m_p1->addmPoints(gamepotpts);
        }else{
                logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                m_p2->addmPoints(gamepotpts);
        }

        updateStats(compCard(c1,c2), gamepotpts, 1);

        //update log
        this->updateLog(logStr);
        
        this->gamepotpts = 0;
        return;

        //compare cards
        //if winner: push to plog info, increment winner points
        //if draw: push to plog info, double pop stack , try winner
        //if cards all finished and still draw split game pot.
    };

void Game::printLastTurn(){
        Log* temp = this->gameLogHead;
        while(temp->next!=nullptr){
                temp = temp->next;
        }
        std::cout << temp->logs << std::endl;
};

void Game::playAll(){
        //runs play turn untill no more cards
        while(this->flagEnded!=1){
                playTurn();
        }
        //this->getP1()->setmStacksize(0);
        //this->getP2()->setmStacksize(0);

        if(m_p1->cardesTaken() == m_p2->cardesTaken()){
                getP1()->getStats()->gamesDrawn++;
                getP2()->getStats()->gamesDrawn++;
                getP1()->getStats()->drawRate = getP1()->getStats()->gamesDrawn/getP1()->getStats()->numberOfGamesPlayed;
                getP2()->getStats()->drawRate = getP2()->getStats()->gamesDrawn/getP2()->getStats()->numberOfGamesPlayed;  
        }else if(m_p1->cardesTaken() > m_p2->cardesTaken()){
                getP1()->getStats()->gamesWon++;
                getP1()->getStats()->WinRate = getP1()->getStats()->gamesWon / getP1()->getStats()->numberOfGamesPlayed;
                getP1()->getStats()->WinRate*= 1.0;
                getP2()->getStats()->WinRate = getP2()->getStats()->gamesWon / getP2()->getStats()->numberOfGamesPlayed;
                getP2()->getStats()->WinRate*= 1.0;
        }else{
                getP2()->getStats()->gamesWon++;
                getP2()->getStats()->WinRate = getP2()->getStats()->gamesWon / getP2()->getStats()->numberOfGamesPlayed;
                getP2()->getStats()->WinRate*= 1.0;
                getP1()->getStats()->WinRate = getP1()->getStats()->gamesWon / getP1()->getStats()->numberOfGamesPlayed;
                getP1()->getStats()->WinRate*= 1.0;
        }
};

void Game::printWiner(){
        if(this->flagEnded == 0){
                return;
        }
        std::string Winner = "";
        //prints winner (playetr with highest points)
        if(getP1()->cardesTaken() == getP2()->cardesTaken()){
                throw(std::invalid_argument("Draw."));
        }else if(getP1()->cardesTaken() > getP2()->cardesTaken()){
                //p1 wins
                Winner+= getP1()->getPlayerName();
                std::cout << Winner + " wins." << std::endl;
        }else{
                //p2 wins
                Winner+= getP2()->getPlayerName();
                std::cout << Winner + " wins." << std::endl;
        }
};

void Game::printLog(){
        //prints the log list
        Log* temp = this->gameLogHead;
        while(temp->next!=nullptr){
                std::cout << temp->logs << std::endl;
                temp = temp->next;
        }
};

void Game::printStats(){
        //for each player prints basic statistics: 
        //win rate, cards won, <other stats you want to print>. 
        //Also print the draw rate and amount of draws that happand. 
        //(draw within a draw counts as 2 draws. )
        std::cout << getP1()->getPlayerName() + " Statistics :" << std::endl;
        getP1()->printStats();
        std::cout << " " << std::endl;
        std::cout << getP2()->getPlayerName() + " Statistics :" << std::endl;
        getP2()->printStats();
        
};

int Game::compCard(Card c1, Card c2){
    //draw
    if(c1.getVal() == c2.getVal()){
        return 0;
    }
    //ace && two cases
    if(c1.getIntValue() == 1 && c2.getIntValue() == 2){
        getP2()->getStats()->beatAce++;
        return -1;
    }
    if(c2.getIntValue() == 1 && c1.getIntValue() == 2){
        getP1()->getStats()->beatAce++;
        return 1;
    }
    //normal cases
    if(c1.getVal()>c2.getVal()){
        return 1;
    }else{
        return -1;
    }
    
}