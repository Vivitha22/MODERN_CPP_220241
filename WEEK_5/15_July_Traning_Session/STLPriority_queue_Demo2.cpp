//this is to avoid the copy constructor

#include "Employee.h"
#include<queue>
#include<iostream>


int main(){

    //priotity is reverse of compartor operator ie.,, ">" means min heap,  "<"  is max heap;
    //comparator
    auto fn =[](const Employee& e1, const Employee& e2){ return e1.experenceYear() < e2.experenceYear() ;};
    std::priority_queue < Employee, std::vector<Employee > , decltype(fn)> pq {fn};
    pq.emplace(101,"Vivitha", 2000.0f, 22, 25.4f);
    pq.emplace(10, "KAvitha", 4000.0f, 25, 24.5f);
    pq.emplace(103,"Vijayakumar", 6000.0f, 27.0f, 26.7f);

    std::cout<<pq.top()<<"\n";
    //time complexity is O(log(n))
}