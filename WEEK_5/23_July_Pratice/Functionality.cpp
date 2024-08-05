#include "Functionality.h"

Hash_fn hash_funciton = [](const EmployeePtr& e)
{return std::hash<Department>()(e->dept());};

Eq_fn eq_fn = [](const EmployeePtr& e1, const EmployeePtr& e2)
{ return e1->dept() == e2->dept();};

// Eq_fn fn = [](const EmployeePtr& e1, const EmployeePtr& e2){
//     return e1->salary() < e2->salary();
// };

void CreateObjects( DataContainer &employee)
{
    employee.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("101"),
        std::forward_as_tuple(std::make_shared<Employee>("101","Vivitha",8000.0f,1,Department::IT))
    );

    employee.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("102"),
        std::forward_as_tuple(std::make_shared<Employee>("102","Kavitha",10000.0f,12,Department::ADMIN))

    );
    
    employee.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("103"),
        std::forward_as_tuple(std::make_shared<Employee>("103","Vijayakumar", 7000.0f,13,Department::HR))
    );  

    employee.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("104"),
        std::forward_as_tuple(std::make_shared<Employee>("104","savitha",4500.0f,14,Department::ADMIN))

    );

    employee.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("105"),
        std::forward_as_tuple(std::make_shared<Employee>("105","Vijay", 7800.0f,5,Department::HR))
    );  

}

std::optional<UnorderSet> ReturnOneEmployee(const DataContainer &employee)
{
    
    std::optional<UnorderSet> result {std::nullopt};
    if(employee.empty())
    {
        std::cerr<<"NO Data found\n";
    }else{

        UnorderSet value {5,hash_funciton,eq_fn};
        for(auto& [k,v]:employee ){
            value.emplace(v);
        }
        result = value;
    }
    return result;
    // for(const EmployeePtr v: value)
}

/*
    - A function to print the details of the employee with maximum salary
    [hint : use max_element]
*/
void DetailsOfEmployeeWithMaxSalary(const DataContainer &employee)
{
    // std::optional<EmployeePtr> result{std::nullopt};
    if(employee.empty()){
        std::cerr<<"No data is found\n";
    }
    auto value = std::max_element(
        employee.begin(),
        employee.end(),
        [](const std::pair<const std::string , EmployeePtr>& e1 , const std::pair<const std::string, EmployeePtr>& e2)
        {return e1.second->salary() < e2.second->salary();}
    );
    std::cout<<"The employee with max salary is : \n "<<*value->second<<"\n";

}

/*
     - A function to return a map of instances which satisfy the predicate passed as a parameter while calling the function
    [Hint: Use copy_if]
*/

std::optional<DataContainer> ReturnMatchingInstance(const DataContainer &employee, const  Predicate &fn)
{
    std::optional<DataContainer>  result {std::nullopt};
    if(employee.empty()){
        std::cerr<<"No data is found\n";
    }

    else{
        DataContainer value {};
         std::copy_if(
            employee.begin(),
            employee.end(),
            std::inserter(value, value.begin()),
            fn
        );
        result = value;
    }
    return result;
    // return std::optional<DataContainer>();
}

std::optional<bool> CheckIfAllVehicles(const DataContainer &employee)
{
    if(employee.empty()){
        std::cerr<<"No data found\n";
    }
    auto result = std::all_of(
        employee.begin(),
        employee.end(),
        [](const std::pair<std::string, EmployeePtr>& e1){return e1.second->experience() > 10;}
    );
    return result;

}
