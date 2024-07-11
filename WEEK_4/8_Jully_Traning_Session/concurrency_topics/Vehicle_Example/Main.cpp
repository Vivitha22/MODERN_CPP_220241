#include "Operation.h"

int main(){

    //step 1 : make objects
    Operation::CreateCarsAndBikes();
    //step 2 : execute parallel functions
    Operation::MapThreads();
    Operation::JoinThreads();

    //step3::serial function
   
    std::future<std::optional<unsigned int>> result1 = std::async(Operation::FindSeatCountForGivenId,"B1");

    std::optional<unsigned int> res1 = result1.get();
    
    if(res1.has_value()){
        std::cout<<"Seat count for id is :"<<res1.value()<<"\n";
    }
    std::future<std::optional<VrType>> result2 = std::async(Operation::ReturnMatchingInstance,"C1");
    std::optional<VrType> res2 = result2.get();


    if(res2.has_value()){
        std::cout<<"Matching instance found "<<"\n";
        std::visit([](auto&& val){std::cout<<*val<<"\n" ;}, res2.value());
    }

    Operation::Deallocate();
}
