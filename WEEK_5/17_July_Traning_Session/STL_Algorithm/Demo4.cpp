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

    std::vector<Employee> result{};

    CreateObjects(stackptr);
    CreateObjects(rawpointers);
    CreateObjects(smartPointers);

    //1)
    //copy if the condition works ------->conditional if copy function
    std::copy_if(
        stackptr.begin(),
        stackptr.end(),

        //create a inserter pointer, if space is not allocated, do it automatically.
        std::inserter(result,result.begin()),
        [](const Employee& e){ return e.age() > 27.0f;}
        
    );

    
    for(Employee& e:result){
        std::cout<<e<<"\t";
    }

    //2:
    // to copy n no.of values   ----------->  copy_n
    std::vector<Employee> n_result{};
    std::copy_n(
        stackptr.begin(),
        2,
        std::inserter(n_result,n_result.begin())
    );
    // for ( Employee& v: n_result){
    //     std::cout<<v<<"\n";
    // }
    // std::cout<<n_result<<"\n";
    std::vector<Employee*> result_pointers {rawpointers.size()};



    //example 3 : copy all items from rawpointeremployees into a destination------>copy all the datas to the pointers
    std::copy(
        rawpointers.begin(),
        rawpointers.end(),
        result_pointers.begin()
    );


}