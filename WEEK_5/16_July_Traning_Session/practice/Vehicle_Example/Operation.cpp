#include "Operation.h"

std::mutex mt;


void CreateCarsAndBikes(DataContainer &data)
{
    // data.emplace(new Bike("B1", 8500.0f));
    // data.emplace(new Bike("B2", 9500.0f));
    // data.emplace(new Car("C1", 800000.0f, 4));
    // data.emplace(new Car("C2", 95600.0f, 3));
    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("B1"),
        std::forward_as_tuple(std::make_shared<Bike>("B1",8500.0f))
    );
    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("B2"),
        std::forward_as_tuple(std::make_shared<Bike>("B1",5500.0f))
    );
    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("C1"),
        std::forward_as_tuple(std::make_shared<Car>("C1",5200.0f,4))
    );
    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("C2"),
        std::forward_as_tuple(std::make_shared<Car>("C2",51200.0f,4))
    );
}

 void FindAverageCost(const DataContainer& data,std::string id)
{
    if (data.empty())
    {
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }
    float total{0.0f};
    // unsigned int
    for (auto&  [k,v] : data)
    {
        std::visit([&](auto &&val)
                   { total += val->price(); }, v);
    }
    if (!data.empty())
    {
        mt.lock();
        std::cout << "The average cost is : " << total / data.size() << "\n";
        mt.unlock();
    }
}

std::optional<VrType> ReturnMatchingInstance(const DataContainer& data,std::string id)
{
    if (data.empty())
    {
        // mt.lock();
        std::cerr << "Empty data container\n";
        // mt.unlock();
    }
    std::optional<VrType> result{std::nullopt};
    bool m_id_flag {false};

    for (auto&  [k,v]  : data)
    {
        std::visit([&](auto &&val)
                   {if(val->id() == id){ result = v; m_id_flag = true; } } , v ); 
        if(m_id_flag){
             break;
        }
    }
    
    // return std::optional<VrType>()
    return result;
}





void DisplayInsuranceAmount(const DataContainer& data){
    if(data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n"; 
        mt.unlock();  
    }
    for(auto&  [k,v] :data){
        std::visit([](auto&& val){mt.lock(); std::cout<<val->InsuranceAmount()<<"\n";mt.unlock();}, v);
    }
}


std::optional<unsigned int>FindSeatCountForGivenId(const DataContainer& data,std::string id)
{
    if(data.empty()){
        std::cerr << "Empty data container\n";   
    }
    std::optional<unsigned int>result {std::nullopt};
    bool matchFound {false};
    for(auto&  [k,v] :data){
        //checking that the object is car and have the id
        if(std::holds_alternative<std::shared_ptr<Car>>(v)){
            std::shared_ptr<Car> temp = std::get<0>(v);
            if(temp->id() == id){
                matchFound = true;
                result = temp->seatCount();
            }
        }

    }
    if(!matchFound && !data.empty()){
        mt.lock();
        std::cerr<<"Id not found\n";
        mt.unlock();
    }
    return result;
    // return std::optional<VrType>(;
}


void MapThreads(ThreadContainer& threads, const DataContainer& data){
    threads.emplace_back(&FindAverageCost,std::ref(data),"C1");
    // threads.emplace( ReturnMatchingInstance, "b1");
    threads.emplace_back(&DisplayInsuranceAmount,std::ref(data));
    // threads.emplace( FindSeatCountForGivenId, "c1");
}

void JoinThreads(ThreadContainer& threads)
{
    for(std::thread& th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}


