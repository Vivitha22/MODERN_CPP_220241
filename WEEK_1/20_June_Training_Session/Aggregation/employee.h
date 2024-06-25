#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "project.h"

class employee
{
private:
    /* data */
    int _id;
    std::string _name;
    project& _p;
    
    
public:
    employee(int id, std::string name, project& p);
    ~employee();

    employee(employee&&)= delete;
    employee operator=(employee(employee&)) = delete; 
    employee(const employee&) = delete;
    employee operator = (employee(const employee&))= delete;
    employee()=default;

    int id() const { return _id; }

    std::string name() const { return _name; }

    project& p() const { return _p; }
};

#endif // EMPLOYEE_H
