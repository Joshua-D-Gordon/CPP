//include doctest for testing, Magical container files
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>
//using nmaespaces to avoid collision and shorter writting
using namespace ariel;
using namespace std;
///////////////////////////////////////////////////////START///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Test case for adding elements to the MagicalContainer
TEST_CASE("Adding elements to MagicalContainer") {
    MagicalContainer container; // default emepty container

    SUBCASE("no elements") {
        CHECK(container.size() == 0); // no currnt elements size should be 0
    }

    SUBCASE("Adding a single element") {
        container.addElement(1);
        CHECK(container.size() == 1); // one lement added, size should be 1
    }

    SUBCASE("Adding multiple elements a random amount of times") {
        //between 1 - 1000 times
        int randomNumber = rand() % 1000 + 1; // from geeks.com (JUST THIS LINE)
        //adding a randomnum amount of times the element
        for(int i = 0; i< randomNumber;i++){
            CHECK_NOTHROW(container.addElement(i));//should be abale to add all elements
        }
        //size should be randomNumber
        CHECK(container.size() == randomNumber);
    }

    SUBCASE("Adding multiple elements twice") {
        //between 1 - 1000 times
        int randomNumber = rand() % 1000 + 1;
        for(int i = 0; i< randomNumber;i++){
            //adding
            container.addElement(i);
            //re-adding second time
            CHECK_THROWS_AS(container.addElement(i),runtime_error); // cant add element if it exists
        }
        //size should be of the random number
        CHECK(container.size() == randomNumber);
    }

    SUBCASE("Adding multiple elements twice but first removing") {
        //between 1 - 1000 times
        int randomNumber = rand() % 1000 + 1;
        for(int i = 0; i< randomNumber;i++){
            //adding
            container.addElement(i);
            //adding a second time
            CHECK_THROWS_AS(container.addElement(i),runtime_error);
            //removing
            container.removeElement(i);
            //readding
            CHECK_NOTHROW(container.addElement(i));
        }
        CHECK(container.size() == randomNumber);
    }

    SUBCASE("Adding multiple elements negitave elements") {
        //between 1 - 1000 times
        int randomNumber = rand() % 1000 + 1;
        for(int i = 0; i< randomNumber;i++){
            container.addElement(-i);
            //adding again
            CHECK_THROWS_AS(container.addElement(-i),runtime_error);
            //removing
            container.removeElement(-i);
            //re adding
            CHECK_NOTHROW(container.addElement(-i));
        }
        //size should be the size of the random number
        CHECK(container.size() == randomNumber);
    }

}

// Test case for removing elements from the MagicalContainer
TEST_CASE("Removing elements from MagicalContainer") {
    MagicalContainer container;

    SUBCASE("Removing an existing element") {
        container.addElement(10);
        container.addElement(20);
        CHECK_NOTHROW(container.removeElement(10)); // can remove as it exists
        CHECK(container.size() == 1);
    }

    SUBCASE("Removing a non-existing element") {
        container.addElement(1);
        container.addElement(2);
        CHECK_THROWS_AS(container.removeElement(3), runtime_error); // 3 dose not exist should throw error
        CHECK(container.size() == 2); //siz should remain 2
    }

    SUBCASE("Removing a existing element twice") {
        container.addElement(10);
        container.addElement(20);
        CHECK_NOTHROW(container.removeElement(10)); // can remove
        CHECK_THROWS_AS(container.removeElement(10), runtime_error); // cant remove as dose not exist
        CHECK(container.size() == 1);
    }

    SUBCASE("Removing a element from empty data structure") {
        CHECK_THROWS_AS(container.removeElement(1), runtime_error); 
        CHECK(container.size() == 0); 
    }

    SUBCASE("Removing a negitave element from empty data structure") {
        CHECK_THROWS_AS(container.removeElement(-1), runtime_error);
        CHECK(container.size() == 0);
    }

    SUBCASE("Removing a negitave element from data structure") {
        container.addElement(-1);
        CHECK_NOTHROW(container.removeElement(-1));
        CHECK(container.size() == 0);
    }
}

TEST_CASE("Retriving size of container") {
    MagicalContainer container;

    SUBCASE("emepty data structure") {
        CHECK(container.size() == 0); // size should be 0
    }

    SUBCASE("Removing an existing element") {
        container.addElement(1);
        container.addElement(2);
        CHECK(container.size() == 2);
        CHECK_NOTHROW(container.removeElement(1));
        CHECK(container.size() == 1);
    }

    SUBCASE("Removing a non-existing element") {
        container.addElement(10);
        container.addElement(20);
        CHECK_THROWS_AS(container.removeElement(30), runtime_error);
        CHECK(container.size() == 2);
    }

    SUBCASE("adding and removing a random amount of elements") {
        int randomNumber = rand() % 1000 + 1;
        int randomNumberRemove = randomNumber / (rand() % 10 + 1); // between 10-100% of elements
            for(int i = 0; i< randomNumberRemove;i++){
                
                container.addElement(i);
                container.removeElement(i);
            }
            for(int i = randomNumberRemove;i<randomNumber;i++){
                container.addElement(i);
            }
            //size should be the size of the random number - removed
            CHECK(container.size() == randomNumber - randomNumberRemove);
    }
    
}

// Test case for the AscendingIterator
TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    int randomNumber = rand() % 1000 + 1; // random num between 1 - 1000
    for(int i = 0; i< randomNumber;i++){
        if(i%2 == 0){
            //add from the start
            container.addElement(i);
        }else{
            //add from the end
           container.addElement(randomNumber-i-1); 
        }
    }
    //hence, not ordered accendingly.


    SUBCASE("Iterating over elements") {
        MagicalContainer::AscendingIterator it(container);
        for(int i = 0; i<randomNumber-1; i++){
            CHECK(*it == i);
            ++it;
        }
        ++it;
        CHECK(it == it.end());
        
    }


    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::AscendingIterator it(emptyContainer);
        CHECK(it == it.end());
    }
    

}

// Test case for the SideCrossIterator
TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);

    SUBCASE("Iterating over elements") {
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 40);
        ++it;
        CHECK(*it == 20);
        ++it;
        CHECK(*it == 30);
        ++it;
        CHECK(it == it.end());
    }

    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::SideCrossIterator it(emptyContainer);
        CHECK(it == it.end());
    }

    SUBCASE("Iterating over an random container") {
        MagicalContainer randomcontainer;
        int randomnum = rand() %1000 + 1;
        for(int i = 0; i<randomnum; i++){
            randomcontainer.addElement(i);
        }
        MagicalContainer::SideCrossIterator itter(randomcontainer);
        for(int i = 0; i<randomnum-1; i++){
            if(i%2 == 0){ // if index even
                CHECK(*itter == i/2);
            }else{ //if index odd
                CHECK(*itter == randomnum - i/2 - 1);
            }
            ++itter;
        }
        ++itter;//for cheecking the end of itterator
        CHECK(itter == itter.end());
    }

    SUBCASE("aceding != sidecross") {
        //make sure are not the same ordered
        MagicalContainer::AscendingIterator itacd(container);
        MagicalContainer::SideCrossIterator itsdc(container);
        //amount of matchs and the total size
        int matchs = 0;
        int sizes = 0;
        //loop through continer
        for (auto it = itacd.begin(); it != itacd.end(); ++it) {
            sizes++;
            //if match
            if(*itacd == *it && *itsdc == *it){
                matchs++;
            }
            //move to next element
            ++itacd;
            ++itsdc;
        }
        //check not the same
        CHECK(sizes!=matchs);
    }
}

// Test case for the PrimeIterator
TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    SUBCASE("Iterating over elements") {
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == it.end());
    }

    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::PrimeIterator it(emptyContainer);
        CHECK(it == it.end()); // should be at end as no elements
    }
    //only primes in aceding order so should be the same
    SUBCASE("acsd is same as prime") {
        MagicalContainer pcontainer;
        pcontainer.addElement(2);
        pcontainer.addElement(3);
        pcontainer.addElement(5);
        pcontainer.addElement(7);
        pcontainer.addElement(11);
        pcontainer.addElement(13);
        pcontainer.addElement(17);
        pcontainer.addElement(19);
        pcontainer.addElement(23);
        MagicalContainer::PrimeIterator itp(pcontainer);
        MagicalContainer::AscendingIterator ita(pcontainer);
        int sizes = 0;
        int matchs = 0;

        for (auto it = itp.begin(); it != itp.end(); ++it) {
            sizes++;
            //if match
            if(*itp == *it && *ita == *it){
                matchs++;
            }
            //move to next element
            ++itp;
            ++ita;
        }
        //check ARE the same
        CHECK(sizes==matchs);
    }
    //not the same order
    SUBCASE("acsd is NOT same as prime") {
        MagicalContainer pcontainer;
        pcontainer.addElement(2);
        pcontainer.addElement(3*2);//not prime
        pcontainer.addElement(5);
        pcontainer.addElement(7*2);//not prime
        pcontainer.addElement(11);
        pcontainer.addElement(13*2);//not prime
        pcontainer.addElement(17);
        pcontainer.addElement(19*2);//not prime
        pcontainer.addElement(23);
        MagicalContainer::PrimeIterator itp(pcontainer);
        MagicalContainer::AscendingIterator ita(pcontainer);
        int sizes = 0;
        int matchs = 0;

        for (auto it = itp.begin(); it != itp.end(); ++it) {
            sizes++;
            //if match
            if(*itp == *it && *ita == *it){
                matchs++;
            }
            //move to next element
            ++itp;
            ++ita;
        }
        //check not the same
        CHECK(sizes!=matchs);
    }
}
//--------------------------------------------------------------
// Test case for comparing iterators from the same container
TEST_CASE("Comparing iterators from the same container") {
    MagicalContainer container;
    int randomnum = rand() %1000 + 1;
    for(int i = 0; i<randomnum; i++){
        container.addElement(i);
    }

    SUBCASE("Comparing AscendingIterator with itself") {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing SideCrossIterator with itself") {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing PrimeIterator with itself") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }
}
//------------------------------------------------------
// Test case for traversing the AscendingIterator
TEST_CASE("Traversing AscendingIterator") {
    MagicalContainer container;
    container.addElement(-10);//negitave numbers
    container.addElement(-2);
    container.addElement(0);//zero
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Iterating in ascending order") {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == -10);
        ++it;
        CHECK(*it == -2);
        ++it;
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 14);
        ++it;
        CHECK(it == it.end());
    }
}

// Test case for traversing the PrimeIterator
TEST_CASE("Traversing PrimeIterator") {
    MagicalContainer container;
    container.addElement(-5);// |prime|
    container.addElement(-1); //negitave number
    container.addElement(-17);
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Iterating over prime elements") {
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == it.end());
    }
}

// Test case for the SideCrossIterator
TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Iterating in side-cross order from start to end") {
        MagicalContainer::SideCrossIterator it(container);

        CHECK(*it == 1);
        ++it;
        CHECK(*it == 14);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(it == it.end());
    }
}
//-------------------------------------------------------
// Test case for comparing AscendingIterator
TEST_CASE("Comparing AscendingIterator") {

    SUBCASE("Comparing iterators after increments") {
        MagicalContainer newcontainer;
        int randomnum = rand() %1000 + 1;
        for(int i = 0; i<randomnum; i++){
            newcontainer.addElement(i);
        }
        MagicalContainer::AscendingIterator it1(newcontainer);
        MagicalContainer::AscendingIterator it2(newcontainer);
        for (int i = 0; i<randomnum-1;i ++){
            CHECK((it1 == it2));
            CHECK_FALSE((it1 != it2));
            CHECK_FALSE((it1 > it2));
            CHECK_FALSE((it1 < it2));

            ++it1;
            CHECK_FALSE((it1 == it2));
            CHECK((it1 != it2));
            CHECK((it1 > it2));
            CHECK_FALSE((it1 < it2));

            ++it2;
        }
        ++it1;
        ++it2;
        CHECK(it1 == it1.end());
        CHECK(it2 == it2.end());
        CHECK_FALSE((it1 > it2));
        CHECK_FALSE((it1 < it2));
    }
}


// Test case for comparing PrimeIterator
TEST_CASE("Comparing PrimeIterator") {
    MagicalContainer container;
    int randomnum = rand() %1000 + 1;
    for(int i = 0; i<randomnum; i++){
        container.addElement(i);
    }

    SUBCASE("Comparing iterators after increments") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        for(int i = 0; i<randomnum && it1!=it1.end(); i++){ // untill last or untill end
            CHECK((it1 == it2));
            CHECK_FALSE((it1 != it2));
            CHECK_FALSE((it1 > it2));
            CHECK_FALSE((it1 < it2));

            ++it1;
            CHECK_FALSE((it1 == it2));
            CHECK((it1 != it2));
            CHECK_FALSE((it1 < it2));
            CHECK((it1 > it2));

            ++it2;
        }
        CHECK(it1 == it1.end());
        CHECK(it2 == it2.end());
    }
}

// Test case for comparing SideCrossIterator
TEST_CASE("Comparing SideCrossIterator") {
    MagicalContainer container;
    int randomnum = rand() %1000 + 1;
    for(int i = 0; i<randomnum; i++){
        container.addElement(i);
    }

    SUBCASE("Comparing iterators after increments") {
        MagicalContainer::SideCrossIterator itStart1(container);
        MagicalContainer::SideCrossIterator itStart2(container);
        for(int i = 0; i< randomnum; i++){
            CHECK((itStart1 == itStart2));
            CHECK_FALSE((itStart1 != itStart2));
            CHECK_FALSE((itStart1 > itStart2));
            CHECK_FALSE((itStart1 < itStart2));

            ++itStart1;
            CHECK_FALSE((itStart1 == itStart2));
            CHECK((itStart1 != itStart2));
            CHECK_FALSE((itStart1 < itStart2));
            CHECK((itStart1 > itStart2));

            ++itStart2;
        }
    }
}
//---------------------------------------------------
TEST_CASE("Iterator Increment Beyond End") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    SUBCASE("Ascending Iterator") {
        MagicalContainer::AscendingIterator it(container);

        // Increment until the end
        while (it != it.end()) {
            ++it;
        }
    
        // Attempt to increment beyond the end
        CHECK_THROWS_AS(++it, runtime_error);
    }

    SUBCASE("Prime Iterator") {
        MagicalContainer::PrimeIterator it(container);

        // Increment until the end
        while (it != it.end()) {
            ++it;
        }

        // Attempt to increment beyond the end
        CHECK_THROWS_AS(++it, runtime_error);
    }

    SUBCASE("SideCross Iterator") {
        MagicalContainer::SideCrossIterator it(container);

        // Increment until the end
        while (it != it.end()) {
            ++it;
        }

        // Attempt to increment beyond the end
        CHECK_THROWS_AS(++it, runtime_error);
    }
}
//checking that the iterators dont impact each other
TEST_CASE("Multiple Iterators Test") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);
    container.addElement(8);
    container.addElement(9);

    SUBCASE("Ascending Iterators") {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);

        ++(++it1);
        CHECK(*it1 == 3);
        ++it2;
        CHECK(*it2 == 2);
        ++(++(++it1));
        CHECK(*it2 == 2);
        CHECK(*it1 == 6);
    }

    SUBCASE("SideCross Iterators") {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);

        ++it1;
        CHECK(*it1 == 9);
        ++it2;
        CHECK(*it2 == 9);
        ++it1;
        CHECK(*it2 == 9);
        CHECK(*it1 == 2);
        ++(++(++it2));
        CHECK(*it2 == 3);
    }

    SUBCASE("Prime Iterators") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);

        ++it1;
        CHECK(*it1 == 3);
        CHECK(*it2 == 2);
        ++it2;
        ++it1;
        CHECK(*it2 == 3);
        CHECK(*it1 == 5);
        ++(++it2);
        CHECK(*it2 == 7);
    }
}
// Test case for the AscendingIterator with negative and positive numbers
TEST_CASE("AscendingIterator with Negative and Positive Numbers") {
    MagicalContainer container;
    container.addElement(-3);
    container.addElement(5);
    container.addElement(-2);
    container.addElement(0);
    container.addElement(4);
    container.addElement(-1);
    container.addElement(3);
    container.addElement(-4);
    container.addElement(2);
    container.addElement(1);

    SUBCASE("Iterating over elements") {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == -4);
        ++it;
        CHECK(*it == -3);
        ++it;
        CHECK(*it == -2);
        ++it;
        CHECK(*it == -1);
        ++it;
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == it.end());
    }
}

// Test case for the PrimeIterator with no prime numbers in the container
TEST_CASE("PrimeIterator with No Prime Numbers") {
    MagicalContainer container;
    container.addElement(4);
    container.addElement(6);
    container.addElement(8);
    container.addElement(9);
    container.addElement(10);
    container.addElement(12);

    SUBCASE("Iterating over elements") {
        MagicalContainer::PrimeIterator it(container);

        CHECK(it == it.end());
        CHECK_THROWS_AS(++it, runtime_error);
    }
}

// Test case for the SideCrossIterator with a single element in the container
TEST_CASE("SideCrossIterator with Single Element") {
    MagicalContainer container;
    container.addElement(100);

    SUBCASE("Iterating over elements") {
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 100);
        ++it;
        CHECK(it == it.end());
    }
}

TEST_CASE("operator= throws when iterators are pointing at different containers") {
    MagicalContainer container1;
    MagicalContainer container2;

    container1.addElement(1);
    container1.addElement(2);
    container1.addElement(3);

    container2.addElement(4);
    container2.addElement(5);
    container2.addElement(6);    

   SUBCASE("AscendingIterator")
   {
        MagicalContainer::AscendingIterator it1(container1);
        MagicalContainer::AscendingIterator it2(container2);

        CHECK_THROWS_AS(it1 = it2, std::runtime_error);
   }
   SUBCASE("SideCrossIterator")
   {
        MagicalContainer::SideCrossIterator it1(container1);
        MagicalContainer::SideCrossIterator it2(container2);

        CHECK_THROWS_AS(it1 = it2, std::runtime_error);
   }
   SUBCASE("AscendingIterator")
   {
        MagicalContainer::PrimeIterator it1(container1);
        MagicalContainer::PrimeIterator it2(container2);

        CHECK_THROWS_AS(it1 = it2, std::runtime_error);
   }
}


