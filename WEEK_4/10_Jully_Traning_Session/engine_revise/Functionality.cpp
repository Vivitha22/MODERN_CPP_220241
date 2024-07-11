#include "Functionality.h"

std::mutex mt;

void CreateObjects(DataContainer &data)
{
    data.emplace_back(new Engine("101", EngineType::ALTERNATE_FUEL,45,12.0f,2));
    data.emplace_back(new Engine("102",EngineType::HYBRID,36.2f,6.2f,3));
    data.emplace_back(std::make_shared<Engine>("103",EngineType::ALTERNATE_FUEL,78.3f,75.2f,8));
    // data.emplace_back();
}

std::optional<DataContainer> ReturnMatchingContainer(const DataContainer &data, const Predicate &fn)
{
    if(data.empty()){
        std::lock_guard<std::mutex> lk(mt);
        std::cerr<<"Data is empty";
    }
    DataContainer result{};
    for(const EnginePtr e : data){
        if(fn(e)){
            result.emplace_back(e);
        }
    }
    if(!data.empty() && result.empty()){
        return std::nullopt;
    }
    else if(!data.empty() && !result.empty()){
        return result;
    }
    else{
        return std::nullopt;
    }
    
}

bool AtleastOneObjectMeetsCondition(const DataContainer &data, const Predicate &Fn)
{
    if(data.empty()){
        std::lock_guard<std::mutex> lk(mt);
        std::cerr<<"Data is empty";
    }
    for(const EnginePtr e:data){
        if(Fn(e)){
            return true;
        }
    }
    return false;
}

//doubt
int AverageOfEngineCc(const DataContainer &data)
{
    if(data.empty()){
        std::lock_guard<std::mutex> lk(mt);
        std::cerr<<"Data is empty";
    }
    float total{0.0f};
    for(const EnginePtr e:data){
        total += e->engineCc();
    }
    // std::cout<<"The average of Engine CC is :"<<total<<"\n";
    return total;
}
