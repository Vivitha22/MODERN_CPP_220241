#include"Functionalities.h"

int main(){
    DataContainer data{};

    createObjects(data);

    auto Fn=[](const EnginePtr& engine){return engine->engineTorque()>20;};
    std::future<std::optional<DataContainer>> result =  std::async(&ReturnMatchingContainer,std::ref(data),Fn);
    std::optional<DataContainer>  res1 = result.get();
    if(res1.has_value()){
        for(const std::shared_ptr<Engine> val:res1.value()){
            std::cout<<"Matching instance found : \t"<< *val <<"\n";
        }
    }


    auto fn = [](const EnginePtr& engine){return engine->engineType() == EngineType::HYBRID ; };
    std::future<bool> result2 = std::async(&AtleastOneInstanceMatching,std::ref(data),fn);
    std::cout<<std::boolalpha << result2.get()<<"\n"; 

    
             //return type
    std::future<int> result3 = std::async(&AverageEngineCC,data);
    std::cout<<"Average : \t"<<result3.get()<<"\n";

}