#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include<list>
#include "Project.h"
using EmployeeContainer = std::list<Employee*>;
using projectContainer = std::list<Project*>;
using predicate = std::function<bool(const Employee*)>;

void CreateObjects(EmployeeContainer& employees, projectContainer& projects);




void Deallocate(EmployeeContainer& employees, projectContainer& projects);

/* 
    add features to filter employees based on filter predicates
            (function style)[FILTER LAMBDA]   
*/

void filterEmployees(const predicate fn, const EmployeeContainer& employees);

void DisplayProjectBudget(const EmployeeContainer& employees);
#endif // FUNCTIONALITIES_H
