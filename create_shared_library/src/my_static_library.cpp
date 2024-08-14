#include "my_static_library.hpp"
#include "iostream"

void staticPrint(const std::string& str){
    std::cout<<"This is the Static Printer:\n";
    std::cout<<str;
}
