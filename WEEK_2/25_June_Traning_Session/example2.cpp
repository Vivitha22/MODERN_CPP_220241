#include<iostream>
#include<vector>
#include<functional> // header file for functional programming

/*
    wrapper class:
    std::funciton wrapper
*/

using logic = std::function<void (int32_t)>;
using dataContainer = std::vector<int32_t>;

void Adaptor(logic fn, dataContainer& data){
    for(int32_t val:data){
        fn(val);
    }
}

int main(){
    dataContainer data {1,2,3};

    //lamdas are also like 

    //fn is the one holding the lamda function 
    //lamda functions are identifed with "[]" brackets
    auto fn = [] (int32_t number){
        std::cout<<number * number * number<<"\n";
    };

    Adaptor(fn,data);
    Adaptor(
        [](int32_t number) {std::cout<< number * 100<<"\n";},
        data
    );

    Adaptor(
        [](int32_t number){ std::cout<<number * 0.1f<<"\n"; },
        data
    );
}