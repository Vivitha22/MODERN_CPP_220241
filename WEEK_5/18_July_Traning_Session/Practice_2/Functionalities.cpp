#include "Functionalities.h"

std::mutex mt;

// HashingFun hash_fn = [](const VehiclePtr &e)
// { return std::hash<MultimediaType>()(e->vehicleMultimediaType()); };

// Eqfun eq_fn = [](const VehiclePtr &v1, const VehiclePtr &v2)
// { return v1->vehicleMultimediaType() == v2->vehicleMultimediaType(); };

// Eqfun fn = [](const VehiclePtr &v1, const VehiclePtr &v2)
// { return v1->vehiclePrice() < v2->vehiclePrice(); };



std::function<bool(const VehiclePtr& , const VehiclePtr& )> comparison_fn = [](const VehiclePtr &v1, const VehiclePtr &v2 ){
    return v1->vehicleMultimediaType() == v2->vehicleMultimediaType();
};


/*
    auto hash_fn=

auto eq_fn =

auto fn =
*/

void CreateObjects(DataContainer &data)
{
    data.emplace_back(std::make_shared<Vehicle>(VehicleType::COMMERCIAL, VehicleStandard::BS4, FuelType::ALTERNATE_FUEL, EngineType::HYBRID, MultimediaType::ANALOG, 9000.0f));
    data.emplace_back(new Vehicle(VehicleType::PRIVATE, VehicleStandard::BS4, FuelType::ICE, EngineType::NA, MultimediaType::ANDROID_SMART, 8000.0f));
    data.emplace_back(new Vehicle(VehicleType::RENTAL, VehicleStandard::BS6, FuelType::OTHER, EngineType::REGULAR, MultimediaType::APPLE_ANDROID_SMART, 7000.0f));
    data.emplace_back(new Vehicle(VehicleType::COMMERCIAL, VehicleStandard::NS6_2, FuelType::ALTERNATE_FUEL, EngineType::HYBRID, MultimediaType::APPLE_SMART, 6000.0f));
    data.emplace_back(new Vehicle(VehicleType::PRIVATE, VehicleStandard::OTHER, FuelType::OTHER, EngineType::NA, MultimediaType::APPLE_SMART, 5000.0f));
}

std::optional<PriorityQueue> HighestVehiclePrice(const DataContainer &data)
{
    Comparator fn;
    PriorityQueue pf(data.begin(), data.end(),fn);
    return pf;
    // return PriorityQueue();
}

std::optional<unorderSet> ReturnMatchingVehicle(const DataContainer &data)
{

    std::optional<unorderSet> result {std::nullopt};

     if (data.empty())
    {
        std::lock_guard<std::mutex> lk{mt};
        std::cerr << "NO data found\n";
    }
    else{
        unorderSet value{data.begin(), data.end(), data.size(), hash_logic,comparison_fn};
        result = value;
    }
    return result;

    // return DataContainer();
}

std::optional<unsigned int> CountOfVehicleObjects(const DataContainer &data, const MultimediaType mtype)
{

    std::optional<unsigned int> result{std::nullopt};

    if (data.empty())
    {
        // std::lock_guard(std::mutex (lk:mt));
        std::lock_guard<std::mutex> lk{mt};
        std::cerr << "NO data found\n";
        // result = std::nullopt;
    }

    else
    {
        result = std::count_if(
            data.begin(),
            data.end(),
            [&](const VehiclePtr &v)
            {
                return mtype == v->vehicleMultimediaType();
                // m_is_data_fount = true;
            });
    }
    // if(result.has_value()){
    //     return result;
    // }
    // std::cerr<<"No data is found\n";

    return result;
}

std::optional<DataContainer> ReturnInstance(const DataContainer &data, const Predicate &fn)
{

    std::optional<DataContainer> result{std::nullopt};
    if (data.empty())
    {
        std::lock_guard<std::mutex> lk{mt};
        std::cerr << "NO data found\n";
    }

    else
    {
        DataContainer value{};
        std::copy_if(
            data.begin(),
            data.end(),
            std::inserter(value, value.begin()),
            fn);

        if (!value.empty())
        {
            result = value;
        }
        else
        {
            std::cerr << "No data satisfied the predicated function passed by the user\n";
        }
    }

    return result;
}

std::optional<bool> CheckAllVechilesPrice(const DataContainer &data)
{
    if (data.empty())
    {
        std::lock_guard<std::mutex> lk{mt};
        std::cerr << "NO data found\n";
    }

    auto result = std::all_of(
        data.begin(),
        data.end(),
        [](const VehiclePtr &v)
        {
            return v->vehiclePrice() > 90000.0f;
        });
    return result;
}

void AverageCalculation(const DataContainer &data)
{
    float result = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float answer, const VehiclePtr &v)
        {
            return answer + v->CalculateRegistrationCose();
        });

    std::cout << "The average is: " << result / data.size() << "\n";
}

std::optional<DataContainer> ReturnLastNItems(const DataContainer &data, const unsigned int N)
{

    std::optional<DataContainer> result{};
    if (data.empty())
    {
        std::lock_guard<std::mutex> lk{mt};
        std::cerr << "NO data found\n";
    }
    if (N > data.size())
    {
        std::cerr << "N is in valid as it is more than size\n";
    }
    else
    {
        DataContainer value{};
        std::copy_n(
            // data.begin() + data.size() - N,
            data.rbegin(), // this will read the inputs from the back wards
            3,
            std::inserter(value, value.begin()));
        result = value;
    }
    return result;
}