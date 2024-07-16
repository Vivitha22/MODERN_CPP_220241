
#include "Operation.h"

int main(){
    DataContainer data{};
    ThreadContainer threads{};
    //step 1 : make objects
    CreateCarsAndBikes(data);
    //step 2 : execute parallel functions
    MapThreads(threads,data);
    JoinThreads(threads);

    std::future< std::optional<unsigned int>> result1 = std::async(&FindSeatCountForGivenId,std::ref(data),"B1");
    std::optional<unsigned int> res1=result1.get();
    if(res1.has_value()){
        std::cout<<"Seat count for id is :"<<res1.value()<<"\n";

    }
    std::future<std::optional<VrType>> result2 = std::async(&ReturnMatchingInstance,std::ref(data),"C1");
    std::optional<VrType> res2 = result2.get();
    if(res2.has_value()){
        std::cout<<"Matching instance found "<<"\n";
        std::visit([](auto&& val){std::cout<<*val<<"\n" ;}, res2.value());
    }


}