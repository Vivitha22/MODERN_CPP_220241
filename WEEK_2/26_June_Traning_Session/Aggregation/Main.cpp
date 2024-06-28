#include "Functionalities.h"

int main() {
    // Employee* employees[3];
    // Project* projects[3];

    std::list<Employee*> employees;
    std::list<Project*> projects;
    CreateObjects(employees, projects);

    //filter all employees whose project team count is above 10;
    auto fn= [](const Employee* emp) {return emp->project().get().teamSize() > 10; };

    filterEmployees(fn,employees);
    DisplayProjectBudget(employees);
    Deallocate(employees, projects);
}

/*
from means passed value
conversion from "Lambda [] (Employee *emp)->void"

to value means expected parameter as pas function declaration

std::function<bool(const Employee* )>
*/
