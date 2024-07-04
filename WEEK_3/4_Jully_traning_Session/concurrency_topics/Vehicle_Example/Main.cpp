#include "Operation.h"

int main(){

    //step 1 : make objects
    Operation::CreateCarsAndBikes();

    //step 2 : execute parallel functions
    Operation::MapThreads();
    Operation::JoinThreads();
     Operation::FindAverageCost();

     Operation::DisplayInsuranceAmount();

    std::optional<unsigned int> result1 = Operation::FindSeatCountForGivenId("b1");

    if(result1 .has_value()){
        std::cout<<"Seat count for id is :"<<result1.value()<<"\n";

    }

    std::optional<VrType> result2 = Operation::ReturnMatchingInstance("c1");

    if(result2.has_value()){
        std::cout<<"Matching instance found "<<"\n";
        std::visit([](auto&& val){std::cout<<*val<<"\n" ;}, result2.value());
    }

    Operation::Deallocate();
}