#include<iostream>
#include <vector>

void Deallocate(std::vector<int*>&& values){
    for(int* v:values){
        delete v;
    }
}

void Magic(const std::vector<int*>& values){
    for(int * v:values){
        std::cout<<*v<<"\n";
    }
    Deallocate(std::move(values));
}

int main(){
    std::vector<int*>data {new int {10}, new int{20}};
    Magic(std::move(data));
    // accessing data variable after move is complete
    //WILL BE UNDEFINED BEHAVIOUR

}