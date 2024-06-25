/*
    Employee
        - int id, string name, string designation, categorical Department, float salary

    
*/

#include <iostream>
#include "Department.h"



class Employee
{
private:

    // The {} brakets are used to declare the default values
    //FEATURE 1
    unsigned int m_id {0}; // this zero represent the default value
    std::string m_name {""}; //default value for the string m_name
    std::string m_designation {"executive"};
    Department m_dept {Department::IT};
    float m_salary {0.0f};
public:

    /*
        to enable any feature we use default 
        to disable any feature we use delete

        These are the defaulted and deleted member functions
    */
    //FEATURE 3
    Employee() = default; // enable the default constructor {which is given in the private}
    ~Employee() = default; //destructure id enabled
    //this says that duplication of employee is not allowed
    Employee(const Employee& other) = delete; //disable copy constructor 
    Employee& operator=(const Employee& other) = delete;
    Employee(Employee&& other) = delete;//move constructor
    Employee& operator=(Employee&& other)=delete;


    //member {value} --> member list initalization 
    // FEATURE 6
    Employee(unsigned int id, std::string name, std::string des, Department dept, float salary): m_id {id}, m_name{name}, m_designation{des}, m_dept{dept}, m_salary{salary} {

    }

        // this->m_dept =dept;
        // this->m_designation =des;
        // this->m_id = id;
        // this->m_name=name;
        // this->m_salary =salary;


};


int main(){

     // Employee *e1= new Employee(); //heap object
    //FEATURE 4
    Employee* ptr = nullptr; //declaration of pointer ptr of type Employee -->better way to declare the pointer 
    //we replaced NULL with nullptr

    ptr = new Employee(); //default constructor
    ptr = new Employee(101, "vivitha", "Trainee", Department ::IT , 20000.0f); // parameterized constructor
    //FEATURE 5
    // int n1 {10};
    //FEATURE 7
    auto n1{10};
    // int* ptr {nullptr};
    int arr[3] {1,2,3};
    Employee e1{};
    Employee e2{102,"vivi", "Admin", Department::ADMIN,8000.0f};   
}

