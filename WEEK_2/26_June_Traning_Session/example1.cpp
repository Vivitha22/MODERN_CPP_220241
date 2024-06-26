/*
     more about lambdas
    1} WHA ARE THEY EXACTLY?
    2) WHAT IS [] WITH ALMBAS?
        if we want to access objects. variables created in the closing function of the lambda, we use[] i.e,. capture closure

    3) some wierd things about lambdas.
*/


#include<iostream>
#include<functional>

void add(int32_t n1, int32_t n2){
    std::cout<<n1+n2<<"\n";
}

int main(){
    /*
        lambda object is bound to fn variable in the scope of main function
    */

    auto fn= [](int32_t n1, int32_t n2){ std::cout<<n1 + n2 <<"\n";};
    fn(10,20); //overloaded() operator of a class created in the background
}



/*
    capture calss

    int n1 = 10;
    int n2= 20;
    int n3 = 30;

    example1 :use of no captured variable
        auto fun = [](){std :: cout <<"hellow world"; };

    example 2 : use of no captured variables but passed parameters

        auto fn=[] (int n1, int n2){std::cout << n1+n2;};
        fn(n1,n2);

    example3 : use n1 as captured variable. n1 should be coped into the lambda

        auto fn=[n1] (int n1, int n2){std::cout << n1+n2;};
        fn(n2); // only n2 is passed as n1 we already captured
    
    example4 : use n1 as captured variable. n1 should be referred into the lambda

        auto fn [ &n1 ] (int n2){std::cout<<n1+n2; };
        fn(n2); //only n2 is passed as n1 was alreay captured by regerence

    example 5 : capture all variables from the surrounding (make them all accessible in the lambda). {copies everything into the lambda when they are accessed int the body of the lambda}

    auto fn= [=] (){std::cout<< n1+n2 + n3 ; };
    fn(); //all variables were copied by capture into the lambda

    note :  if we use = in [] they are passed as const values. so they cannot be changes only read and display.

    example 6 : if we want to change them and not to pass the values as const we can sent the reference of the values

    auto fn= [&] () {std::cout<< n1+n2 + n3 ; };
    fn(); //all variables were copied by capture into the lambda

    THIS WILL SEND THE REFERENCES OF THE VALUE,  WHICH CAN BE CHANGED

*/