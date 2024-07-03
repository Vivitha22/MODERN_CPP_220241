#include"BusinessOwner.h"
#include"Employee.h"
#include<variant>

using VrType = std::variant<BusinessOwner,Employee>;
// void Display(const std::variant<eBusinssOwner>)

void Display(const VrType& v){
    // if( std::get<0>(v)){

    // }

    // try{
    //     eBusinssOwner& b = std::get<0>(v);
    //     std::cout<< b <<"\n";
    // }
// orrr

    //this will not work because no pointer is used

    std::visit([](auto&& val){std::cout<<val<<"\n";},v);
    //           what to do->return or print   ,    the variant on which parameter it should perform is "v"
    //the auto  && is used when we dono what is the data type in this case we have businessowner and employee 

}

int main(){

    // std::variant<eBusinssOwner,Employee> vr;
    VrType vr;
    Employee e1 {"Vivitha", 9000.0f};
    BusinessOwner b1 {"Kavitha",89000.0f};
    vr = e1; //change vr to take BusinessOwner
    Display(vr);

    vr = b1;
    Display(vr);
}