#include "employee.h"

employee::employee(int id, std::string name, project &p) : _id{id}, _name{name},_p(p)
{
}

employee::~employee()
{
    std::cout<<"The employee with id : "<<_id<<" is deleted\n";
}
