#include<iostream>
#include<stack>
#include "Employee.h"

/*
    A stack is never used for accessing all items together.. NOLOOPING OPERATIONS
*/

int main(){
    std::stack<Employee> s{};

    //pusp operations int stack
    s.emplace(101,"Vivitha", 2000.0f,22,2.0f); 
    s.emplace(10, "KAvitha", 4000.0f,25,25.0f);
    s.emplace(103,"Vijayakumar", 6000.0f,27.0f,26.0f);

    //display() top item and then pop
    std::cout<<s.top() << "\n";
    // std::cout<<s.pop();
    s.pop();
    std::cout<<s.top() << "\n";
    s.pop();
    std::cout<<s.top() << "\n";
    s.pop();

    std::cout<<s.size()<<"\n";
    

    std::cout<<"Check empty : " <<std::boolalpha<<s.empty()<<"\n";

}