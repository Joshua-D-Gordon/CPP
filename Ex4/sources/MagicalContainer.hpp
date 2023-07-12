//header gaurd
#pragma once
//includes for data structure (vector), iostream (printing), cmath (math operations)
#include <iostream>
#include <vector>
#include <cmath> // for isPrime function.


namespace ariel{
//Container class
class MagicalContainer {
private:
    //vector data structure
    std::vector<int> dataStructure;
public:
    //default constructor
    MagicalContainer();
    
    //adding element to vector
    void addElement(int element);
    //removing element vector
    void removeElement(int element);
    //returning vector size - size_t for machine independentcy
    size_t size() const {
        return dataStructure.size();
    }
    //assigment operator
    MagicalContainer& operator=(const MagicalContainer &other);

    //iterators should NOT be detached from class
    //ascending iterator
    class AscendingIterator {
    private:
        //*container , atIndex in vector data structure
        const MagicalContainer* container;
        size_t atIndex;

    public:
        //constructors:
        AscendingIterator(const MagicalContainer& container): container(&container), atIndex(0) {}
        AscendingIterator(const MagicalContainer& container, size_t atIndex): container(&container), atIndex(atIndex){}
        //assigment operator
        AscendingIterator operator=(const AscendingIterator &other);
        //boolean operators
        bool operator==(const AscendingIterator& other) const{
            return atIndex == other.atIndex;
        }
        bool operator!=(const AscendingIterator& other) const{
            return !(*this == other);
        }
        bool operator>(const AscendingIterator& other) const{
            return atIndex > other.atIndex; 
        }
        bool operator<(const AscendingIterator& other) const{
            return atIndex < other.atIndex; 
        }
        //derefrence operator
        int operator*() const;
        //++ operator (atIndex)
        AscendingIterator& operator++();
        //begin and end for iterator
        AscendingIterator begin() const {
            return MagicalContainer::AscendingIterator(*this->container,0);
        }
        AscendingIterator end() const {
            return MagicalContainer::AscendingIterator(*this->container, container->size());
        }
    };
    //sidecross iterator
    class SideCrossIterator {
    private:
    //*container , atIndex in vector data structure
        const MagicalContainer* container;
        size_t atIndex;
    public:
        //constructors
        SideCrossIterator(const MagicalContainer& container): container(&container), atIndex(0) {}
        SideCrossIterator(const MagicalContainer& container, size_t atIndex): container(&container), atIndex(atIndex) {}
        //assigment operator
        SideCrossIterator operator=(const SideCrossIterator &other);
        //boolean operators
        bool operator==(const SideCrossIterator& other) const { 
            return atIndex == other.atIndex; 
        }
        bool operator!=(const SideCrossIterator& other) const { 
            return !(*this == other);
        }
        bool operator>(const SideCrossIterator& other) const { 
            return atIndex > other.atIndex; 
        }
        bool operator<(const SideCrossIterator& other) const { 
            return atIndex < other.atIndex; 
        }
        //derefrence operator
        int operator*() const;
        //++ operator (atIndex)
        MagicalContainer::SideCrossIterator& operator++();
        //begin and end for iterator
        SideCrossIterator begin() const {
            return MagicalContainer::SideCrossIterator(*this->container,0);
        }
        SideCrossIterator end() const {
            return MagicalContainer::SideCrossIterator(*this->container, container->size());
        }
    };
    //Prime iterator
    class PrimeIterator {
        private:
        //container , atIndex in vector data structure
            const MagicalContainer* container;
            size_t atIndex;
        public:
            //constructors
            PrimeIterator(const MagicalContainer& container): container(&container), atIndex(0) {
                while (atIndex < container.size() && !isPrime(container.dataStructure[atIndex])) {
                    ++atIndex;
                }
            }
            PrimeIterator(const MagicalContainer& container, size_t atIndex): container(&container), atIndex(atIndex) {}
            //assigment operator
            PrimeIterator operator=(const PrimeIterator &other);
            //is number a prime number function
            bool isPrime(int num) const;
            //boolean operators
            bool operator==(const PrimeIterator& other) const {
                return atIndex == other.atIndex;
            }
            bool operator!=(const PrimeIterator& other) const {
                return !(*this == other);
            }
            bool operator>(const PrimeIterator& other) const {
                return atIndex > other.atIndex;
            }
            bool operator<(const PrimeIterator& other) const {
                return atIndex < other.atIndex;
            }
            //++ operator (atIndex)
            PrimeIterator& operator++();
            //begin and end for iterator
            PrimeIterator begin() const {
                return PrimeIterator(*container, atIndex);
            }
            PrimeIterator end() const {
                return PrimeIterator(*container, container->size());
            }
            //derefrence operator
            int operator*() const ;
        };

};
}