#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include"Employee.h"
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<functional>
#include<future>
#include<algorithm>
#include<numeric>
#include<queue>
#include<thread>


using EmployeePtr = std::shared_ptr<Employee>;
using DataContainer = std::unordered_map<std::string, EmployeePtr>;

using Predicate = std::function<bool(const std::pair<const std::string, EmployeePtr>&)>;
using Hash_fn =  std::function<bool(const EmployeePtr&)>;
using Eq_fn = std::function<bool(const EmployeePtr&, const EmployeePtr&)>;


extern Hash_fn hash_funciton;
extern Eq_fn eq_fn;
extern Eq_fn fn;

using PriorityQueue = std::priority_queue<EmployeePtr,DataContainer,decltype(fn)>;
using UnorderSet = std::unordered_set<EmployeePtr,decltype(hash_funciton),decltype(eq_fn)>;



void CreateObjects( DataContainer& employee);

/*
    - A function to return one Employee of each department 
    from the data container. 
    Hint: If there are 5 objects with types HR, ADMIN, HR, IT, return the first 3 objects only (unique category objects)
    [Hint: Create an unordered_set]
*/

std::optional<UnorderSet> ReturnOneEmployee  (const DataContainer& employee);

/*
    - A function to print the details of the employee with maximum salary
    [hint : use max_element]
*/

void DetailsOfEmployeeWithMaxSalary(const DataContainer& employee);

/*
     - A function to return a map of instances which satisfy the predicate passed as a parameter while calling the function
    [Hint: Use copy_if]
*/

std::optional<DataContainer> ReturnMatchingInstance(const DataContainer& employee, const Predicate& fn);

/*
    - A function to check if all employee have experience above 10.0f or not
    [Hint: all_of]
*/

std::optional<bool> CheckIfAllVehicles(const DataContainer& employee);

#endif // FUNCTIONALITY_H
