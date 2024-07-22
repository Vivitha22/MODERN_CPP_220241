#include "Employee.h"
#include<queue>
#include<iostream>

/*
    1) what kind of data goes into priority queue?
    2) what is the backend of the queue to store the dat?  //vector is default
    3) what is the comparison logic(also called "comparator")?
*/

int main(){
    std::vector<Employee> employees {};
    employees.emplace_back(101,"Vivitha", 2000.0f, 22, 27.4f); 
    employees.emplace_back(10, "KAvitha", 4000.0f, 25, 25.0f);
    employees.emplace_back(103,"Vijayakumar", 6000.0f, 27.0f, 26.0f);

    //all employee which are in the vector must be inserted into heap using heapify();

    //comparator
    auto fn =[](const Employee& e1, const Employee& e2){ return e1.experenceYear() > e2.experenceYear() ;};
    std::priority_queue<Employee,std::vector<Employee>, decltype(fn)> pq {employees.begin(), employees.end(),fn};

    std::cout<<pq.top()<<"\n";


}

/*
    Cpp is strongly & statically typed language :
    1) everything has a type, including functins!

    2) a lambda in cpp is an object that behaves like a function

    3) lambda is always implemented by the compiler by creating a class dring compilation. Name of this class is unknown to us!

    4) so my requirement is : compiler should create a fn lambda.  Its type will be known to compiler.

    The declaraed data type for fn is what i obtain to obtain from the compiler
    
*/