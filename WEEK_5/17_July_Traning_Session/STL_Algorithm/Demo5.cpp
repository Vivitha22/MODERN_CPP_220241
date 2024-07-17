#include<iostream>
#include<memory>
#include<list>
#include <algorithm>
#include "../Employee.h"
#include<numeric> //this has to be included if you want ot use accumulate

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

    float result = std::accumulate(
        stackptr.begin(),
        stackptr.end(),
        0.0f,
        //this lambda is called binary operation lambda, which takes 2 operator of any type
        [](float ans_upto_now, const Employee& e){ 
            return ans_upto_now + e.salary();
        }
    );

    std::cout<<"The total salary is: "<<result<<"\n";
}