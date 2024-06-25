/*
    problems in the regular enum
*/

#include <iostream>

enum class Gear{
    FIRST,
    SECOND
};

enum class Rank{
    FIRST,
    SECOND
};

void Magic(int n1){
    std::cout<< 100*1 <<"\n";
}


int main()
{
    FIRST; // problem 1 : not mandatory to prefix enum name (confusion) -- BUT WE HAVE TO GIVE
    Gear g1= Gear::FIRST;
    Rank r1 = Rank::FIRST;

    if(g1 == r1) //problem 2 : enums for 2 differnt type and category get compared on the basis of inter value -- THIS SHOULD NOT HAPPEN
    {
        std::cout<<  "Noooo!!!" <<"\n";
    } 

    Magic(r1); // Problem 3 :: auto conversion of enum to interger without consent !! 
    /*
    IT IS NOT A GOOD THING BECAUSE YOUR NOT CONTROLLING THE CODE CAUSE IT IS CONVERTING AUTOMATICALLY
    */
}

/*
----------------------------------------------------
   STOP using enum without prefix                   |
   STOP comparing the 2 different type of enums     |
   STOP auto conversion of enum to int              |
                                                    |
   So to OVERCOME THIS PROBLEMS we use ENUM CLASS   |
----------------------------------------------------
*/