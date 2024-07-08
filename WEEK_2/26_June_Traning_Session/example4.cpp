/*
    std::reference_wrapper<T>:
        this is a wrapper class to "hold
        reference type T
*/

#include<iostream>
#include<functional>
#include<vector>

void Magic(std::reference_wrapper<int> data){
    std::cout<<data<<"\n";
}
int main(){
    int n1=10;
    int &n2 = n1;
    // int& ref=n1; //ref is a reference to n1
    std::reference_wrapper<int> ref = n1; //reference to n1
    // ref is an alternate name for n1 in the main function

    //ref is an alternate name for n1 in main function

    Magic(n1);  //int&data = n1; 

    //int& arr[1] {ref};

    // std::vector<int&> val {n2};

    std::reference_wrapper<int> arr[1] {ref};

    std::vector<std::reference_wrapper<int>>v1 {ref};
    // std::vector<std::reference_wrapper<int>>v2;

    std::cout<< v1[0].get();

    //reference pointer can autoconvert

}
