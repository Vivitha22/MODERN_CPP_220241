#include<iostream>
#include<variant>
#include<list>

int main(){
    std::variant<int , std::string>  vr  {10};
    vr = {std::list<int>{1,2,3}};
}