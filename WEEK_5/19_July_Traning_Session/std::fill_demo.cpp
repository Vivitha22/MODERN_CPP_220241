/*
    If i have memory locatons already allocated upto a certain size, I can "fill" all locations 

    for e.g: std::vector<int> data {5}; //size 5 vector
 
    std::fill( data.begin(), data.end(), 11);
 
    result: data: {11,11,11,11,11}
 
    for e.g: std::array<int,5> arr{}; //array of 5 location
 
    std::fill(arr.begin(), arr.end(), 11);
 
    result: arr: {11,11,11,11,11}
*/


#include<iostream>
#include<memory>
#include "Employee.h"
#include<vector>
#include <algorithm>


using StackMemoryEmployees = std::vector<Employee>;
using RawPointerHeapEmployee = std::vector<Employee*>;
using EmployeePtr = std::shared_ptr<Employee>;
using SmartPointerHeapEmployee = std::vector<EmployeePtr>;



int main(){
    StackMemoryEmployees stackptr{5};
    RawPointerHeapEmployee rawpointers{5};
    SmartPointerHeapEmployee smartPointers{5};

    std::fill(
        stackptr.begin(),
        stackptr.end(),
        Employee{}
    );

    std::fill(
        smartPointers.begin(),
        smartPointers.end(),
        std::make_shared<Employee>()
    );
}

    