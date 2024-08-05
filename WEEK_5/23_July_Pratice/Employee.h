#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include "Department.h"

class Employee
{
private:
    std::string m_id{""};
    std::string m_name{""};
    float m_salary{0.0f};
    unsigned int m_experience{0};
    enum Department m_dept{Department::ADMIN};

    
public:
    Employee()=default;
    ~Employee() = default;
    Employee(const Employee&)=delete;
    Employee& operator=(const Employee&)= delete;
    Employee(Employee&&)=delete;
    Employee& operator=(Employee&&)= delete;

    Employee(std::string id,std::string name,float salary,unsigned int experience, Department dept);

    std::string id() const { return m_id; }

    std::string name() const { return m_name; }

    float salary() const { return m_salary; }

    float experience() const { return m_experience; }

    Department dept() const { return m_dept; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    // friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) ;

    

};

#endif // EMPLOYEE_H
