#include "log.hpp"

using namespace ariel;
//constructors
Log::Log(){
    this->logs = "";
    this->next = nullptr;
}
//constructor and initilize next to null pointer
Log::Log(std::string logstr){
    this->logs = logstr;
    this->next = nullptr;
}

