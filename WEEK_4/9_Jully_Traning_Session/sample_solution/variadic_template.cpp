/*
    cpp11 : create a function in c++ that can accept 1 or more arguments

*/

#include<iostream>

//base case : only 1 argument for addition

/*
    add is a function 

*/

//if it takes one parameter
// template <typename T>
// T add(T val){
//     return val;
// }

// //if it takes 1 or more --> it will take the first number out and calls recursion, adds the remaining number 

// // ... -> is called ellipsis , used to say one or more things
// template<typename T, typename... other>
// auto add(T n1, other... args){
//     return n1 + add(args...);
// }

// or in cpp17 we use to do
//fold expresion
template <typename... T>
auto add(T... n1){
    return (n1+ ...);  //{1,2,3,4}  -> (1+(2+3))
}

int main(){
    std::cout<<add<int>(1,2,3)<<"\n";
    std::cout<<add<int>(1)<<"\n";
    std::cout<<add<int>(1,2)<<"\n";
}


/*
    add(1,2,3,4,5)

    (1+ (2+(3+(4+(5))) // n1 + ...right associative
*/

/*
    substract

    left associative operation

    ( (1- 2) - 3) = -1 -3= -4
*/