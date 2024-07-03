/*
    KEEP DATA on the heap 
    and user variant for "functional polymorphism"
*/

#include<iostream>
#include<variant>
#include "Employee.h"
#include "BusinessOwner.h"

using VrType = std::variant<BusinessOwner*,Employee*>;

/*
    A funciton which either accepts another function as a parameter or returns a function is called "Higher-order" function
*/

void Display(const VrType& v){
    std::visit([](auto& val){std::cout<<*val<<"\n";}, v);
}

void ShowPFAmoung(const VrType& v){
    bool flag {false};
    if( std::holds_alternative<Employee*>(v))
    {
        flag = true;
        Employee* o = std::get<1>(v);
        o->calculateMonthlyPF();
    }
    if(!flag)
    {
        throw std::runtime_error("Not a valid for businessowner type data");
    }
}


//you will not use visit for uncommon behaviours this will give compile time error
//common behaviour can be executed using visit
void ShowTaxAmount(const VrType& v){
        std::visit([](auto&& val){val->calculateTaxAmount();} ,   v  );
}

int main(){
    VrType v;
    v = new BusinessOwner{"Vivitha", 900000.0f};

    Display(v);
    // ShowPFAmoung(v);
    ShowTaxAmount(v);

    v=new Employee{"Kavitha",58900.0f};
    Display(v);
    try{
        ShowPFAmoung(v);
    }
    catch(std::runtime_error& ex){
        std::cout<<ex.what()<<"\n";
    }
    ShowTaxAmount(v);

    // v= new Employee{"Vivi", 8922.0f};


}