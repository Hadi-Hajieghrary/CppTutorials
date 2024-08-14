#include "my_shared_library.hpp"
#include "iostream"

extern "C"{
    void sharedPrint(const std::string& str){
        std::cout<<"This is the Shared Printer:\n";
        std::cout<<str;
    }
}
