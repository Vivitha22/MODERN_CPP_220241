#include<iostream>
#include<memory>
#include<list>
#include <algorithm>
#include "../Employee.h"

using StackMemoryEmployees = std::list<Employee>;
using RawPointerHeapEmployee = std::list<Employee*>;
using EmployeePtr = std::shared_ptr<Employee>;
using SmartPointerHeapEmployee = std::list<EmployeePtr>;


//stack

void CreateObjects(StackMemoryEmployees& stackptr){
    stackptr.emplace_back(  101, "Vivitha" , 20000.0f , 20 , 11.1f);
    stackptr.emplace_back(  102, "kavitha" , 30000.0f , 38 , 12.1f);
}


//raw pointers
void CreateObjects(RawPointerHeapEmployee& rawpointers){

   rawpointers.emplace_back(new Employee(    101, "Vivitha" , 40000.0f , 18 , 13.1f));
   rawpointers.emplace_back(new Employee(   102, "kavitha" , 70000.0f , 22 , 14.1f));
}

//smartpointers
void CreateObjects(SmartPointerHeapEmployee& smartPointers){
    // smartPointers.emplace_back( new Employee( 101, "Vivitha" , 22000.0f , 78 , 17.1f));
    // smartPointers.emplace_back( new Employee(102, "kavitha" , 41000.0f , 48 , 15.1f));
    smartPointers.emplace_back(std::make_shared<Employee>( 103, "Vijaya",5000.0f,14,3.0f));
    smartPointers.emplace_back(std::make_shared<Employee>( 105, "Helo",66000.0f,45,7.0f));


}


int main(){
    StackMemoryEmployees stackptr{};
    RawPointerHeapEmployee rawpointers{};
    SmartPointerHeapEmployee smartPointers{};

    CreateObjects(stackptr);
    CreateObjects(rawpointers);
    CreateObjects(smartPointers);

    //check if all employee have age above 25

    // check all items from begin to end of container

    auto result1 = std::count_if(
         stackptr.begin(),
        stackptr.end(),
        [](const Employee& e1){
            return e1.experenceYear() >8.0f;
        }
    );

    std::cout<<"The count of employees with more than 8 years exoerience is : "<<result1<<"\n";

    auto result2 = std::count_if(
        smartPointers.begin(),
        smartPointers.end(),
        [](const EmployeePtr& e1){
            return e1->experenceYear() > 4.0f;
        }
    );

    std::cout<<"Count of employee with 8 years experence : " <<std::boolalpha << result2<<"\n";

    auto result = std::max_element(
        stackptr.begin(),
        stackptr.end(),
        [](const Employee& e1, const Employee& e2){
            return e1.experenceYear() > e2.experenceYear();
        }
    );
    std::cout<<"The name of the employee with minimum experience is : "<<(*result).name()<<"\n";
}

    
