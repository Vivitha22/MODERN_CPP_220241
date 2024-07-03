#include<iostream>
#include<array>

int main(){
    // a container of fixed size can be used with this syntax

    std::array<int,2> arr{90000,22};
    auto[salary, age]=arr;
}
