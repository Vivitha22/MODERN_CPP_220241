#include "Functionalities.h"

int main() {
    // Employee* employees[3];
    // Project* projects[3];

    std::list<Employee*> employees;
    std::list<Project*> projects;
    CreateObjects(employees, projects);
    // filterEmployees()
    Deallocate(employees, projects);
}