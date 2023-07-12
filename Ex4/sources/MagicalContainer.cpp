#include "MagicalContainer.hpp"

using namespace ariel;
//default constructor
MagicalContainer::MagicalContainer(){
    
}
//adds element to vector then sorts vector
void MagicalContainer::addElement(int element){
    // if element already in data structrue throw error
    for(int i: this->dataStructure){
        if(i == element){
            throw std::runtime_error("already in data structure");
        }
    }
    //push element to vector
    dataStructure.push_back(element);
    //sort data structure
    std::sort(dataStructure.begin(), dataStructure.end());
}
//trys to find element in the vector if no element throws error, else erases element
void MagicalContainer::removeElement(int element){

    for(size_t i=0; i< dataStructure.size(); i++){ // looping over dataStructure
        if(dataStructure[i] == element){ // if element found
            dataStructure.erase(dataStructure.begin() + int(i)); //remove element
            return; // exit
        }
    }
    throw std::runtime_error("Element not found."); // throw error
    
}
//cheecks not same object, assigns data structure returns this (now with new data structure)
MagicalContainer& MagicalContainer::operator=(const MagicalContainer& other){
    if(this!= &other){ // cheeck not the same for unexpected behavior
            this->dataStructure = other.dataStructure;
        }
        return *this;
}
//cheecks this is not other, cheecks this container is ohers container
//assigns atIndex and container
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator& other){
    if (this != &other){
        if (&container != &other.container)// cant assign diffrent containers
            {
                throw std::runtime_error("Iterators from different containers cannot be assinged.");
            }
            // assign atIndex and container
            atIndex = other.atIndex;
            container = other.container;
        }
    
        return *this;
}
//cheecks not out of range and returns element in data structure (vector at atIndex)
int MagicalContainer::AscendingIterator::operator*() const{
    if (atIndex >= container->dataStructure.size()) {
        throw std::out_of_range("index out of range"); // out of range
    }
    return container->dataStructure[atIndex]; // return element atIndex 
}
//cheecks not to go out of bounds , increases atIndex
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
    if(this->atIndex >= container->size()){
        throw std::runtime_error("index out of range"); //out of range
    }
    ++this->atIndex; //++atIndex
    return *this;
}
//cheecks this is not other, cheecks this container is ohers container
//assigns atIndex and container
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if (this != &other)
        {
            if (&container != &other.container)
                {
                    throw std::runtime_error("Iterators from different containers cannot be assinged.");
                }

            atIndex = other.atIndex;
            container = other.container;
        }

    return *this;
}
//cheecks if atIndex is odd returns the element on right of structure at the right location,
//else returns the element at index on the left of data structure / 2 - wich is the right location.
int MagicalContainer::SideCrossIterator::operator*() const { 
    if(this->atIndex%2 == 1){
        return container->dataStructure.at(container->size() - atIndex/2 -1); // return from the end
    }else{
        return container->dataStructure.at(atIndex/2); // return from the begining
    }
}
//cheecks not out of bounds, increase atIndex and returns the iterator
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if (this->atIndex >= this->container->size()){
        throw std::runtime_error("Index out of bounds."); //out of bounds
    }
    ++ this->atIndex;
    return *this;
}
//cheecks this is not other, cheecks this container is ohers container
//assigns atIndex and container
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if (this != &other)
        {
            if (&container != &other.container)
                { // containers are not the same!
                    throw std::runtime_error("Iterators from different containers cannot be assinged.");
                }
            //assigns atIndex and container
            atIndex = other.atIndex;
            container = other.container;
        }

    return *this;
}
//cheecks if number is prime number
bool MagicalContainer::PrimeIterator::isPrime(int num) const {
    if (num <= 1){
        return false; // 1,[0, -infinity] are not prime numbers
    }
    if (num == 2){
        return true; // 2 is a prime
    }
    //Check untill num^0.5 that is not a prime number
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
//cheeck not out of bounds, increments index untill a prime number while not out of bounds
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(atIndex >= container->size()){
        throw std::runtime_error("out of range prime iterator"); //is out of bounds
    }
    ++atIndex; // increment by one
    while (atIndex < container->size() && !isPrime(container->dataStructure[atIndex])) { // if currently a prime will not enter while loop
        ++atIndex;
    }
    return *this;
}
//cheeck not out of bounds, returns element at data structure at the atIndex
int MagicalContainer::PrimeIterator::operator*() const {
    if (atIndex >= container->size()) {
        throw std::out_of_range("Iterator out of range."); // out of range
    }
    return container->dataStructure[atIndex]; // return element atIndex
}