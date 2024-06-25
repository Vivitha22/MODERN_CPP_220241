#ifndef PROJECT_H
#define PROJECT_H

#include<iostream>

class project
{
private:
    std::string _id;
    int teamSize;
    float _budget;
public:
    project(std::string id, int size, float budget);
    ~project();
    project(project&&)= delete;
    project operator=(project(project&)) = delete; 
    project(const project&) = delete;
    project operator = (project(const project&))= delete;
    project()=default;

    std::string id() const { return _id; }

    int getTeamSize() const { return teamSize; }

    float budget() const { return _budget; }

    
};

#endif // PROJECT_H
