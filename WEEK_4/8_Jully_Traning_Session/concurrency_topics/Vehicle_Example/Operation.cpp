#include "Operation.h"

DataContainer Operation::m_data{};
ThreadContainer Operation::m_threads {};
std::mutex Operation::mt{};

void Operation::CreateCarsAndBikes()
{
    m_data.emplace_back(new Bike("B1", 8500.0f));
    m_data.emplace_back(new Bike("B2", 9500.0f));
    m_data.emplace_back(new Car("C1", 800000.0f, 4));
    m_data.emplace_back(new Car("C2", 95600.0f, 3));
    // m_data.emplace_back(nullptr);
}

void Operation::FindAverageCost()
{
    if (m_data.empty())
    {
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }
    float total{0.0f};
    // unsigned int
    for (const VrType v : m_data)
    {
        std::visit([&](auto &&val)
                   { total += val->price(); }, v);
        
    }
    if (!m_data.empty())
    {
        mt.lock();
        std::cout << "The average cost is : " << total / m_data.size() << "\n";
        mt.unlock();
    }
}

std::optional<VrType> Operation::ReturnMatchingInstance(std::string id)
{
    if (m_data.empty())
    {
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }
    std::optional<VrType> result{std::nullopt};
    bool m_id_flag {false};

    for (const VrType v : m_data)
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


void Operation::Deallocate()
{
    if(m_data.empty()){
        std::cerr << "Empty data container\n";   
    }
    // delete m_data;
    for(const VrType v:m_data){
        std::visit([](auto&& val){ delete val;}, v);
    }
}


void Operation::DisplayInsuranceAmount()
{
    if(m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n"; 
        mt.unlock();  
    }
    for(const VrType v:m_data){
        std::visit([](auto&& val){mt.lock(); std::cout<<val->InsuranceAmount()<<"\n";mt.unlock();}, v);
    }
}


std::optional<unsigned int> Operation::FindSeatCountForGivenId(std::string id)
{
    if(m_data.empty()){
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();   
    }
    std::optional<unsigned int>result {std::nullopt};
    bool matchFound {false};
    for(const VrType v:m_data){
        //checking that the object is car and have the id
        if(std::holds_alternative<Car*>(v)){
            Car* temp = std::get<0>(v);
            if(temp->id() == id){
                matchFound = true;
                result = temp->seatCount();
            }
        }

    }
    if(!matchFound && !m_data.empty()){
        mt.lock();
        std::cerr<<"Id not found\n";
        mt.unlock();
    }
    return result;
    // return std::optional<VrType>(;
}


void Operation::MapThreads()
{
    m_threads.emplace_back( Operation::FindAverageCost);
    // m_threads.emplace_back( Operation::ReturnMatchingInstance, "b1");
    m_threads.emplace_back( Operation::DisplayInsuranceAmount);
    // m_threads.emplace_back( Operation::FindSeatCountForGivenId, "c1");
}

void Operation::JoinThreads()
{
    for(std::thread& th : m_threads){
        if(th.joinable()){
            th.join();
        }
    }
}
