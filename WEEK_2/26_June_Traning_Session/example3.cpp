#include<iostream>
#include<functional>
#include<vector>
#include<list>

template <typename T>
void Display(T& data1){
    for(int val:data1){
        std::cout<<val<<"\n";
    }
}

int main(){
    std::list<int> data1{101,20,30};
    std::vector<int>data2 {10,20,22};
    std::array<int,3> data3{10,2,30}; // like a c-style array but without pointer

    Display<std::list<int>>(data1);
    Display<std::vector<int>>(data2);
    Display<std::array<int,3>>(data3);
}