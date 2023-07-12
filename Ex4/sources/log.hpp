#pragma once
#include <string>
#include "card.hpp"

namespace ariel{
    //log linked list
    class Log{
        public:
            std::string logs;
            Log *next;
            //constructors
            Log();
            Log(std::string logstr);
            
    };
}