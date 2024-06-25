#include<iostream>
#include<vector>
#include<functional>

/*
    first class functions

    A language is said to treat "functions" as first-class if the following things are posible in the language

    RUELS
    a) functins have a properly recognizable types.
    b) functions can be passed as parameters to the functions
    c) functions can be returned as parameters from the functions (closures)
    d) functions can be addressed.copied into another variable

                or

        functions can be 'saved' in a variable
    e) functions can be stored in a container
*/

void Magic(std::function<void(const int32_t)> fn){
    fn(10);
}

std::function<void(int32_t)> Demo(){
    return [](const int32_t val) {return val * val * val ;};
}


int main(){
    //Type of fn
    /*
        a function which accepts on int32_t by value, returns void    
    */
   //rule 1
    auto fn = [](const int32_t val){std::cout<<val * val ; };

    //rule2
    Magic(fn); //works

    //rule3
    auto ans=Demo(); //accept the functinon returned in a variable

    //rule 4
    auto temp=ans; // 'function' copied

    auto* ptr = &ans; // addressing also works!


    //rule5
    std::vector<    std::function<void(int32_t)>  > fns{fn};


}