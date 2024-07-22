/*
    async has 2 use case
    1) You can use std::async to fetch data from a thread if the function returns a value

    2) providing inputs to executing threads asynchronously, out of order in "future"

    future and promise model---> you will make a promise to the compiler that you will give the inputs in the future.


*/

#include<iostream>
#include<future>

int* AllocateSpace(){
    return (int*) new int();//return the address of the new allocation
}

int* factorial(std::future<int>& number){
    /*
        1. Primary tastk :Calculate factorial (dependent on input)
        2. make allocation on the heap where the answer will be stored
        3. 
    */
   int* ans = AllocateSpace();
   /*
        .....actual answer calculation startes here!
   */
    //after the subtake is completed
    int number_value = number.get();//factorial thread will be blocked untill user fulfiles the promise

    int result = 1;

    for(int i=2; i<=number_value ; i++){
        result *= i;
    }
    *ans= result; //copy the result on the heap in ans address location

    return ans;
}

int main(){
    std::promise<int> pr; //first , I make a promise to provide an "integer"

    std::future<int> ft= pr.get_future();
    std::future<int*> res = std::async(&factorial, std::ref(ft));
    int data{0};
    std::cin>>data;

    //fullfil promise. send a signal to future attached to the promise it will go to line 30;
    pr.set_value(data);
    std::cout<<*res.get()<<"\n";
}