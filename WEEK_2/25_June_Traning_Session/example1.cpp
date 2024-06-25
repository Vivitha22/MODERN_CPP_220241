//WEEK 2 : MODERAN CPP STARTS

/*
    software to be built
    ----->diagnostics of a car at workshop!
    function program is used when large amount of files are used
*/
/*
    Objective: I want to write an "Adaptor" function which will accept
        a) vector of integer 32 bit numbers
        b) a function that accepts a single iterger 32 values and returns void

    Adaptor should "map" function provided onto the data provided

*/

#include<iostream>
#include<vector>

void Square(int32_t number){
    std::cout<<number*number<<"\n";
}
void Cube(int32_t number){
    std::cout<<number * number * number<<"\n";
}


// void Adaptor(     fn     , std::vector<int32_t> & data){ 

// }

void Adaptor(void (*fn)(int32_t number),std::vector<int32_t>& data)
{
    //for each number in data, run the function with the number
    for(int32_t val:data){
        (*fn)(val);
    }
}

int main(){

    std::vector<int32_t> data {1,2,3,4,5};
    // for(int i:data)
    // {
        Adaptor(&Cube, data);
        Adaptor(&Square, data);
    // }
    // Adaptor(&Cube, data);
    // Adaptor(&Square, data);

    //if we want the user can design their own function and use its loc to process "data"

    // int n1=10;
    // int* ptr= &n1;

    //function pointer -->address of a function

    // void(*ptr)(int32_t) = &Square;
    // // void(int32_t number){}
    // void (*temp)(int32_t)=&cube;

    // (*temp) (10); // call cube fuction as Cube(10)

    // (*ptr)(9); // call square function as square(9);
}