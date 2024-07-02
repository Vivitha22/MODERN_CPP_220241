/*
    3 style of programming:
        - structure programming  
        - object oriented   
        - functional

    Rules of Functional programming
        a)treat functions as if they are objects
        b)if possible, maintain purity of function
        c) functions have catefories based on what they do 
            Example1: a function that transforms x1,x2,x3 into y1,y2,y3 based on a transformation mapping logic is called a "Map function".
        
            e.g data= [1,2,3,4,5]
                fn= (n)->n*n;

            In map function application, number of inputs and outputs in same 
            [101  27000]  [102    90000]     [103    88000]

            fn = (e)->salary *0.1f //as tax

            result = 2700, 9000,8800

            example 2: a function that "removes/identifies" from the input, a select number of values based on a criteria [ filter function ]

            eg: data = [1,2,3,4,5]
                f = n -> n%2 == 0;
                result : [2,4] //only 2 input values satisfy the condition(predicate)

            Example 3: a function that accumulaates/ gathers/aggregates multiple input values into one, final,singular output values [reduce/accumulate functions]

            e.g: data=[1,2,3,4,5]
            fn=(x,y) -> x+y;

            result: 15

        total   1    2    3    4    5
                |    |     |    |    | 
          0     |    |     |    |    |
           1
             1    3    5     7     9
*/ 


#include<iostream>
#include<functional>

using operation = std::function<int32_t(int32_t)>;

void Adaptor(operation fn, int32_t  value){
    std::cout<<fn(value);
}

//just to know
auto Adaptor(operation fn, int32_t  value)->void{
    std::cout<<fn(value);
}

int main(){
    // takes one input of type int32_t by value and returns an int32_t value
    //the funciton should multiply input number by 100

    auto fn = [] (int32_t n) { return n*100 ; };

    //just to know
     auto fn = [] (int32_t n)->int32_t { return n*100 ; };

    int n1=100;
    auto demo_fn = [n1](int32_t num)mutable {n1=99; return num * n1;};


    Adaptor(fn,10);
}