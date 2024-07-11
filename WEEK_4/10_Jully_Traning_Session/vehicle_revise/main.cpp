#include"Functionalities.h"

int main(){

    Functionalities::CreateCarsAndBikes();
    Functionalities::MapThread();
    Functionalities::JoinThread();

    std::future<std::optional<unsigned short>> result1 = std::async(Functionalities::FindSeatCountForGivenId,"c1");
    std::optional<unsigned short> res1 = result1.get();
    if(res1.has_value()){
        std::cout<<"The SeatCount is : "<<res1.value()<<"\n";
    }

    std::future<std::optional<VrType>> result2 = std::async(Functionalities::ReturnMatchingInstance,"c1");
    std::optional<VrType> res2= result2.get();
    if(res2.has_value()){
        std::visit([](auto&& val){std::cout<<*val<<"\n";}, res2.value());
    }
    
}