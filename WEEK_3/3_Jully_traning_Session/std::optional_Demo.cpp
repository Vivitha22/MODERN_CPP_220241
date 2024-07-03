#include<iostream>

#include<optional>

// size_t Factorial(int16_t val){

//     if(val < 0){
//         throw std::invalid_argument("negative number");
//     }

//     if(val == 0 || val == 1){
//         return 1;
//     }
//     else{
//         size_t total {1};
//         for(size_t i=2;i<=val;i++){
//             total += i;
//         }
//         return total;
//     }
// }

//or

//this factorial function takes 1 int16_t by value and optionally returns as size_t (sometimes, not always);

//function MAY OR MAY NOT RETURN A VALUE
std::optional<size_t> Factorial(int16_t val){

    if(val < 0){
        return std::nullopt; //a symbolic data value to indicate "NULL"
    }

    if(val == 0 || val == 1){
        return 1;
    }
    else{
        size_t total {1};
        for(size_t i=2;i<=val;i++){
            total *= i;
        }
        return total;
    }
}

int main(){

    

    if(std::optional<size_t> result = Factorial(-5);result.has_value()){
        std::cout<<"Factorial is : "<<result.value();
    }

    else{
        std::cerr<<"The factorial did not return a value\n";
    }
    
}


/*
    define a function which takes a value
 
    if value is negative, I have nothing to return
 
    else if value is 0 or 1, I should return 1
 
    else {
        do a product of 2...value. Return the total
    }
 
    /////////////////
 
    main code is:
    
    call the function with a value. we get a "surprise" box!
 
    if surprise box has a value, print the value
 
    else{
        show a error message saying "I got nothing in the surprise box"
    }
*/