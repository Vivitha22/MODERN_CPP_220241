// #include<iostream>
// #include<functional>

// void magic(std::string & data){
//     data= "demo";
//     std::cout<<data<<"\n";
// }

// int main(){
//     std::string value{"dummy"};
//     magic(std::ref(value));
// }

#include<iostream>
#include<functional>

int main(){
    int val{100};
    auto fn= [](int32_t n){std::cout<< n*val;};
    fn(100);
}