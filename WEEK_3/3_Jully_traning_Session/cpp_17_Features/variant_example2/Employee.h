#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class Employee
{
private:
    std::string m_name {""};
    float m_salary{0.0f};
public:
    Employee()=default;
    ~Employee() = default;
    // Employee(const Employee&) = default;
    Employee(const Employee&) = delete;
    // Employee& operator=(const Employee&) = default;
    Employee& operator=(const Employee&) = delete;
    Employee(Employee&&)= delete;
    Employee& operator=(Employee&&)=delete;

    Employee(std::string name, float salary): m_name{name},m_salary{salary}{}

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "m_name: " << rhs.m_name
           << " m_salary: " << rhs.m_salary;
        return os;
    }

    //it's not a common function cause it is not in business
    void calculateMonthlyPF(){
        std::cout<<"The PF amount for the Employee is : " <<0.11f * m_salary<<"\n";
    };
    void calculateTaxAmount(){
        std::cout<< "The tax amount for the employee is : " <<0.15*m_salary<<"\n";
    }
};

#endif // EMPLOYEE_H
