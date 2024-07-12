#include<iostream>
#include<variant>

int main(){
    std::variant<int,std::string> vr{};
    std::visit([](auto&& val){std::cout<<val;},vr);
    // std::cout<<std::get<1>(vr);
}