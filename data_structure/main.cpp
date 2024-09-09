#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

class Person
{
    private:
        char* name_;
    public:

        Person(const char* name){
            size_t n = std::strlen(name);
            name_ = new char[n+1];
            std::strncpy(name_, name, n);
            name_[n+1] = '\0';
        }

        void setName(const char* name){
            size_t n = std::strlen(name);
            name_ = new char[n+1];
            std::strncpy(name_, name, n);
            name_[n+1] = '\0';
        }

        char* getName(){
            return name_;
        }
};

int main(int argc, char** argv)
{
    {// Static Array
        constexpr size_t N{100};
        char message[N]{"\0"};
        std::strncpy(message, "I am Hadi!",100);

        std::cout<<"Hello World"<<std::endl;
        std::cout<<message<<std::endl;
    }

    {// Dynamic Array

        size_t N{0};
        std::cout<<"Input the Size of the Char Array: ";
        std::cin>>N;

        char filler{'\0'};
        std::cout<<"Input the Filler Character: ";
        std::cin>>filler;

        char* message = new char[N];
        for (size_t n{0}; n != N; ++n){
            message[n] = filler;
        }
        std::strncpy(message, "I am Not Hadi!", 14);
        message[14] = filler;

        std::cout<<"Hello World"<<std::endl;
        std::cout<<message<<std::endl;
    }

    { // Stack
        std::stack<Person> people;
        Person hadi("Hadi");
        Person shadi{"Shadi"};
        people.push(hadi);
        people.push(shadi);
        people.top().setName("Behzad");
        while(!people.empty()){
            std::cout<<people.top().getName()<<std::endl;
            people.pop();
        }
    }

    {// queue
        std::queue<Person> people;
        Person behzad("Behzad");
        Person hamideh{"Hamideh"};
        Person hadi{"Hadi"};
        Person shadi{"Shadi"};
        people.push(behzad);
        people.push(hamideh);
        people.push(hadi);
        people.push(shadi);
        people.front().setName("Behzad Hajieghrary");
        people.back().setName("Shadi Hajieghrary");

        while(!people.empty()){
            std::cout<<people.front().getName()<<std::endl;
            people.pop();
        }
    }
    return 0;
}