#include<iostream>
#include<variant>
// #include<cctype>

using VrType = std::variant<int, std::string> ;

void DisplayValue(VrType& v){
                //auto&& means forwarded references
    std::visit([](auto&& val){ std::cout<<val<<"\n"; }, v);
}

void ConvertToUpper(VrType& v){
    if(std::holds_alternative<std::string>(v)){
        std::string temp = std::get<1>(v);
        // std::cout<<temp.toupper();
        // std::cout<<temp
        for(char c:temp){
            std::cout<<char((int)c - 32);
        }
    }
}

int main(){
    VrType variant{"vivitha"};
    ConvertToUpper(variant);
    DisplayValue(variant);
}