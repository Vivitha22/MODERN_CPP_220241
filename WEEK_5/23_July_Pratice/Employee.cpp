#include "Employee.h"

Employee::Employee(std::string id, std::string name, float salary, unsigned int  experience, Department dept):m_id{id},m_name{name},m_salary{salary}, m_experience{experience},m_dept{dept}
{
}

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_name: " << rhs.m_name
           << " m_salary: " << rhs.m_salary
           << " m_experience: " << rhs.m_experience
           << " m_dept: " << (int)rhs.m_dept;
        return os;
    }
