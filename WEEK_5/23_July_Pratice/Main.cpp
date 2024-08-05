#include"Functionality.h"

int main(){
    DataContainer data;

    CreateObjects(data);
    // Mapthread(threads);
    std::future<std::optional<UnorderSet>> result1 = std::async(&ReturnOneEmployee,std::ref(data));
    // std::cout<<result1.value();
    std::optional<UnorderSet> res1 = result1.get();
    for(const EmployeePtr& e : res1.value()){
        std::cout<<*e<<"\n";
    }


    auto pre_fn = [](const std::pair<const std::string, EmployeePtr>& e){return e.second->dept() == Department::IT;};
    std::future<std::optional<DataContainer>> result2 = std::async(&ReturnMatchingInstance,std::ref(data),pre_fn);
    std::optional<DataContainer> res2 = result2.get();
    if(res2.has_value()){
        for(auto& [k,v] : res2.value()){
            std::cout<<"The maching instances is : \n"<<*v<<"\n";
        }
    }

    DetailsOfEmployeeWithMaxSalary(data);
    std::future<std::optional<bool>> result3 = std::async(&CheckIfAllVehicles,std::ref(data));
    std::optional<bool> res3 = result3.get();
    if(res3.has_value()){
        std::cout<<"Is all employee having 10 years of experience : "<<std::boolalpha<<res3.value()<<"\n";
    }
}