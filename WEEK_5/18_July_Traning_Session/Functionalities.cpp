#include "Functionalities.h"

HashingFun hash_fn = [](const VehiclePtr& e){return std::hash<MultimediaType>() (e->vehicleMultimediaType() ); };
Eqfun eq_fn = [](const VehiclePtr& v1,const VehiclePtr& v2){return v1->vehicleMultimediaType() == v2->vehicleMultimediaType();};
Eqfun fn=[](const VehiclePtr& v1, const VehiclePtr& v2){return v1->vehiclePrice() < v2->vehiclePrice();};

/*
    auto hash_fn=

auto eq_fn = 

auto fn = 
*/

void CreateObjects(DataContainer &data)
{
    data.emplace_back(std::make_shared<Vehicle>(VehicleType::COMMERCIAL,VehicleStandard::BS4,FuelType::ALTERNATE_FUEL,EngineType::HYBRID,MultimediaType::ANALOG,9000.0f));
    data.emplace_back(new Vehicle(VehicleType::PRIVATE,VehicleStandard::BS4,FuelType::ICE,EngineType::NA,MultimediaType::ANDROID_SMART, 8000.0f));
    data.emplace_back(new Vehicle(VehicleType::RENTAL, VehicleStandard::BS6,FuelType::OTHER,EngineType::REGULAR,MultimediaType::APPLE_ANDROID_SMART,7000.0f));
    data.emplace_back(new Vehicle(VehicleType::COMMERCIAL,VehicleStandard::NS6_2,FuelType::ALTERNATE_FUEL,EngineType::HYBRID,MultimediaType::APPLE_SMART,6000.0f));
    data.emplace_back(new Vehicle(VehicleType::PRIVATE,VehicleStandard::OTHER,FuelType::OTHER,EngineType::NA,MultimediaType::APPLE_SMART,5000.0f));
}

std::optional< PriorityQueue >HighestVehiclePrice(const DataContainer& data)
{
    PriorityQueue pf(data.begin(),data.end(),fn);
    return pf;
    // return PriorityQueue();
}

std::optional<unorderSet> ReturnMatchingVehicle(const DataContainer& data){
    
    std::unordered_set<VehiclePtr,decltype(hash_fn),decltype(eq_fn)> result {5,hash_fn,eq_fn};
    for(const VehiclePtr v:data){
        result.emplace(v);
    }
    return result;

    // return DataContainer();
}

std::optional<unsigned int> CountOfVehicleObjects(const DataContainer& data,MultimediaType mtype){
    auto result = std::count_if(
        data.begin(),
        data.end(),
        [&](const VehiclePtr& v){
            return mtype == v->vehicleMultimediaType();
        }
    );
    return result;
    // return 0;
}

std::optional<DataContainer> ReturnInstance(const DataContainer& data,const Predicate& fn){
    DataContainer result{};

    std::copy_if(
        data.begin(),
        data.end(),
        std::inserter(result,result.begin()),
        fn
    );
    return result;
}

std::optional<bool> CheckAllVechilesPrice(const DataContainer& data){
    auto result = std::all_of(
        data.begin(),
        data.end(),
        [](const VehiclePtr& v){
            return v->vehiclePrice() > 90000.0f;
        }
    );
    return result;
}

void AverageCalculation(const DataContainer &data)
{
    float result = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float answer,const VehiclePtr& v){
            return answer + v->CalculateRegistrationCose();
        }
    );

    std::cout<<"The average is: "<<result/data.size()<<"\n";
}

std::optional<DataContainer> ReturnLastNItems(const DataContainer& data){
    /*
        std::vector<Employee> n_result{};
        std::copy_n(
        stackptr.begin(),
        2,
        std::inserter(n_result,n_result.begin())
    );
    */
    DataContainer result{};
    std::copy_n(
        data.begin()+data.size()-3,
        3,
        std::inserter(result, result.begin())
    );
    return result;
}