#include"Functionalities.h"

int main(){
    DataContainer vehicle{};

    CreateObjects(vehicle);

    std::future< std::optional<PriorityQueue>> result = std::async(&HighestVehiclePrice, std::ref(vehicle));
    std::optional<PriorityQueue> res = result.get();
    if(res.has_value()){
        std::cout<<"The highest vehicle price is :"<<*res.value().top()<<"\n";
    }

    std::future<std::optional<unorderSet>> result2= std::async(&ReturnMatchingVehicle,std::ref(vehicle));
    std::optional<unorderSet> res2 = result2.get();
    if(res2.has_value()){
        for(const VehiclePtr& v: res2.value()){
            std::cout<<"The matching vehicle are : "<<*v<<"\n";
        }
    }

    std::future<std::optional<unsigned int>> result3 = std::async(&CountOfVehicleObjects,std::ref(vehicle),MultimediaType::ANDROID_SMART);
    std::optional<unsigned int> res3 = result3.get();
    std::cout<<"The count of vehicle objects are : "<<res3.value()<<"\n";

    // std::future<st
    auto pre_fn = [](const VehiclePtr& v){return v->engineType() == EngineType::HYBRID;};
    
    std::future< std::optional<DataContainer>> result4 = std::async(&ReturnInstance,std::ref(vehicle),pre_fn);
     std::optional<DataContainer> res4 = result4.get();
     if(res4.has_value()){
        for(const VehiclePtr& v: res4.value()){
            std::cout<<"The instance is : "<<*v<<"\n";
        }
        // std::cout<<"The instances are : "<<res4.value();
     }

    std::future<std::optional<bool>> result5 = std::async(&CheckAllVechilesPrice,std::ref(vehicle));
    std::optional<bool> res5 = result5.get();
    std::cout<<std::boolalpha<<res5.value()<<"\n";

    // std::cout<<"The average if : "<<AverageCalculation(vehicle)<<"\n";

    AverageCalculation(vehicle);

    std::future<std::optional<DataContainer>> result6 =std::async(&ReturnLastNItems,std::ref(vehicle));
    std::optional<DataContainer> res6 = result6.get();
    if(res6.has_value()){
        for(const VehiclePtr& v : res6.value()){
            std::cout<<"The items are "<<*v<<"\n";
        }
    }
}