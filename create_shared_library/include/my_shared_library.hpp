#include <iostream>
#include <string>

extern "C"{
    void sharedPrint(const std::string& str);
}

