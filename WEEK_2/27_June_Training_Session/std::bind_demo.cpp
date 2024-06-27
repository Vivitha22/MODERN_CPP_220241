/*
    std::bind allows us to "refactor"/"repurpose"/"remodel" an existing function to create "partially implemented" functions
*/

/*
    cp  -r  source      destination
*/

//it will help to redirect the input parameter and also to hard code the input

#include<iostream>
#include<functional>

void formula(int x,int y, int z){
    std::cout<<(x+y)-z<<"\n";
}

int main(){
    formula(10 , 20 , 30); /// 0
    formula(20,30,10); ////40

    //swap the parameters
    auto partical_formula= std::bind(&formula, 100,std::placeholders::_1, std::placeholders :: _2); // this swap the x value as 100;
    
    //this placeholder will hold the place for the values given in the function
    
    partical_formula(10,90);//this says that formula(100,10,90)

    auto swap_formula = std::bind(&formula, std::placeholders::_2, std::placeholders::_3, std::placeholders::_1);


    swap_formula(10,20,30); //this means swap_formula(20,30,10)

    auto weired_mapped_function = std::bind(&formula, 100,200, std::placeholders::_2);

    weired_mapped_function(99,10); //the 99 will be discarded cause we're using only the second value i.e., _1 was not used
}