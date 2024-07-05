#include<iostream>
#include<thread>

void formula(int& val, float factor, const std::string& name){
    std::cout<<"Absolutely important work!";
}

int main(){
    int n1 {10};
    std::thread t1 {&formula, std::ref(n1),10,10.21f,"Vivitha"};
}   


//to pass a reference to a thread use std::ref
//thread arguments should be invokeable