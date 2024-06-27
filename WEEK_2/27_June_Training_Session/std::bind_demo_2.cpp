
#include<iostream>
#include<functional>

int main(){
    auto fn = [](int32_t number, int32_t factor) {return number * factor ;};


    //while using bind in lambda function, don't use '&' symbol for function name--> this will give a compilation error

    auto partially_implemented_fn = std::bind(fn, 100, std::placeholders::_1);

    partially_implemented_fn(20);

    partially_implemented_fn(20,1,2,3,4,5,6);
    //this will not give any error instead it will just discard the extra values.

}