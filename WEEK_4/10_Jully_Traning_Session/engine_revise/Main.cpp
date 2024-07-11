#include"Functionality.h"

int main(){
    DataContainer engine;
    CreateObjects(engine);
    auto fn = [](const EnginePtr& e){return e->engineTorque()> 10;};
    std::future< std::optional<DataContainer>> result1= std::async(&ReturnMatchingContainer,engine,std::ref(fn));
    std::optional<DataContainer> res1 = result1.get();
    if(res1.has_value()){
        for(const EnginePtr val : res1.value()){
            std::cout<<*val<<"\n";
        }
    }
    
    auto Fn = [](const EnginePtr& e){return e->type() == EngineType::ALTERNATE_FUEL;};
    std::future<bool> result2 = std::async(&AtleastOneObjectMeetsCondition,engine,std::ref(Fn));
    std::cout<<std::boolalpha<<result2.get() <<"\n";
    
    std::future<int> result3 = std::async(&AverageOfEngineCc,engine);
    
    std::cout<<"The average is : "<<result3.get()<<"\n";

}