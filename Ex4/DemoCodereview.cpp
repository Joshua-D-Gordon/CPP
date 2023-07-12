#include <iostream>
#include "sources/MagicalContainer.hpp"
#include "Matala2/sources/game.hpp"
#include "matala4/Team.hpp"

using namespace std;
using namespace ariel;
int main() {
    cout<<"***************************************************************"<<endl;
    cout<<"***************************DEMO********************************\n"<<endl;

    cout<<"creating container"<<endl;
    // Create a MagicalContainer and add some elements
    MagicalContainer container;

    cout<<"The size of the container once created is: "<< container.size()<<endl;
    
    int a = 17; int b = 2; int cc = 25; int d = 9; int e = 3;
    cout<<"adding five elements: "<<a<<" "<<b<<" "<<cc<<" "<<d<<" "<<e<<" "<<"\n"<<endl;
    container.addElement(a);
    container.addElement(b);
    container.addElement(cc);
    container.addElement(d);
    container.addElement(e);

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;
    
    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;
    
    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    std::cout << std::endl;

    // Remove an element from the container and display the size
    cout<<"removing element: 9"<<endl;
    container.removeElement(9);
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;
    
    cout<<"***********************************************************"<<endl;
    cout<<"***********************************************************\n"<<endl;
    cout<<"MagicContainer created"<<endl;
    MagicalContainer c;
    int randomnum = rand()%100 + 1;
    cout<<"random num drawn between 1 - 100 is: "<< randomnum<<endl;
    for(int i =0; i< randomnum; i++){
        c.addElement(i);
    }
    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter1(c);
    for (auto it = ascIter1.begin(); it != ascIter1.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;
    
    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter1(c);
    for (auto it = crossIter1.begin(); it != crossIter1.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;
    
    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter1(c);
    for (auto it = primeIter1.begin(); it != primeIter1.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    std::cout << std::endl;

    cout<<"***********************************CardWar********************************\n"<<endl;
    Player pOne("p1");
    Player pTwo("p2");
    Game game1(pOne,pTwo);
    MagicalContainer gamec;
    Card *cards = game1.getCard();
    for(int i =0; i<52;i+=4){
        cout<<"card value is: "<<cards[i].getIntValue()<<" of card"<< cards[i].to_string()<<endl;
        gamec.addElement(cards[i].getIntValue());
    }
    //cout<<"printing cards"<<endl;
    //for(int i = 0; i<52; i+=4){
        //cout<<cards[i].to_string()<<" , ";
    //}
    //cout<<endl;
    cout<<"\n"<<"printing card int values in iterators: "<<endl;

    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter2(gamec);
    for (auto it = ascIter2.begin(); it != ascIter2.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;
    
    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter2(gamec);
    for (auto it = crossIter2.begin(); it != crossIter2.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;
    
    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter2(gamec);
    for (auto it = primeIter2.begin(); it != primeIter2.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    std::cout << std::endl;

    cout<<"\n**********************COWBOY-VS-NINJA************************\n"<<endl;
    Cowboy *c1 = new Cowboy("cb1",Point(0,0));
    OldNinja *on1 = new OldNinja("on1", Point(0,0));
    YoungNinja *yn1 = new YoungNinja("yn1", Point(0,0));
    TrainedNinja *tn1 = new TrainedNinja("tn1", Point(0,0));
    Character* ch = new Character(Point(0,0),40,"dummy","C",0,0,0);
    c1->shoot(ch);
    c1->shoot(ch);
    c1->shoot(ch);
    //bullets now = 6 - 3 = 3
    MagicalContainer cvsnconatiner;
    //cout<<c1->getLifepts()<<endl;
    //cout<<c1->getBoolets()<<endl;
    //cout<<on1->getLifepts()<<endl;
    //cout<<on1->getSpeed()<<endl;
    //cout<<yn1->getLifepts()<<endl;
    //cout<<yn1->getSpeed()<<endl;
    //cout<<on1->getLifepts()<<endl;
    //cout<<on1->getSpeed()<<endl;
    //cout<<on1->getSlashpts()<<endl;
    cvsnconatiner.addElement(c1->getLifepts());
    cvsnconatiner.addElement(c1->getBoolets());
    cvsnconatiner.addElement(on1->getLifepts());
    cvsnconatiner.addElement(on1->getSpeed());
    cvsnconatiner.addElement(yn1->getLifepts());
    cvsnconatiner.addElement(yn1->getSpeed());
    cvsnconatiner.addElement(tn1->getLifepts());
    cvsnconatiner.addElement(tn1->getSpeed());
    cvsnconatiner.addElement(tn1->getSlashpts());

    cout<<"\n"<<"printing card int values in iterators: "<<endl;

    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter3(cvsnconatiner);
    for (auto it = ascIter3.begin(); it != ascIter3.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;
    
    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter3(cvsnconatiner);
    for (auto it = crossIter3.begin(); it != crossIter3.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;
    
    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter3(cvsnconatiner);
    for (auto it = primeIter3.begin(); it != primeIter3.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    std::cout << std::endl;
    
    return 0;
}
