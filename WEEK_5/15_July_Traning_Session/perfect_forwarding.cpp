#include<iostream>
#include<memory>
#include "Employee.h"

template<typename T>
void Destination(T&& args){
    std::cout<<args<<"\n";
}



template<typename T, typename... Args>
auto Forward(Args&&... n1){
    Destination<T>( std::forward<Args>(n1)...);
}

int main(){
    // Forward(10);
    Forward<int>(10);
    std::shared_ptr<Employee> sptr = std::make_shared<Employee>(101,"Vivitha", 2000.0f, 22, 25.4f);
}

/*
    1) THIS IS AN ASSIGNMENT OPERATION : RNS HAS TO BE ASSIGNED TO LHS!
        RHS IS EXECUTED FIRST

    2) RHS IS A FUNCITION. FUNCTIONS ARE CALLED WITH PARAMETERS!   5 PARAMETERS HAVE BEEN PROVIDED

*/
/*
    what is a forwarding function , how to recognize it?

        The forwarding function is a template function that acceptd parameters to call function F

        It will always be variable functions
        It will always use the built in tool std::forward

        All peraferters received int the function shall be of type "Something" with the syntax
            <function-name>(Something&& values)
        ie., the function shall reeive on templated parameters using with '&&'


    void magic(int&& data);
-------------------------------
    templete<typename T>
    void magic(T&&  data);
*/