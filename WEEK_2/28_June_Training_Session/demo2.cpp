#include<iostream>
#include<functional>

void formula(int& x, int y, int z){
    std::cout<<x+y+z <<"\n";
}

int main(){
    int a=10;
    auto binded_formula = std::bind(&formula, std::ref(a),100, std::placeholders::_1);
    binded_formula(99);

    //called formula (by coping x, assinging 100 to y and assigning 99 to z)
    //create a reference wrapper for a variable to be pass in the place of x

    // std::reference_wrapper<int> ref{a}; or see line 10 std::ref(a);

}