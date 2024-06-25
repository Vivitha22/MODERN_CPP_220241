#include "project.h"

project::project(std::string id, int size, float budget): _id{id}, teamSize{size}, _budget{budget} 
{
}

project::~project()
{
    std::cout<<"The project with id : "<<_id<<" us delete\n";
}
