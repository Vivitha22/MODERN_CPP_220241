#include "functionality.h"

void createObeject(container &e, Container &p)
{

    p.emplace_back(new project("1", 2 , 20.0f));
    e.emplace_back(new employee(101,"vivi", *p[0]));

    p.emplace_back(new project("2",5,8451.2f));
    e.emplace_back(new employee(102,"kjh",*p[1]));
    
}

void deallocate(container &e, Container &p)
{
    for(const employee* v:e){
        delete v;
    }
    for(const project* s:p){
        delete s;
    }
}
