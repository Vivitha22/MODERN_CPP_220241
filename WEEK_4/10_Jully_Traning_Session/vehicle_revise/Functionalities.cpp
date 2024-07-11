#include "Functionalities.h"

Datacontainer Functionalities::m_data{};
ThreadContainer Functionalities::m_threads{};
std::mutex Functionalities::mt{};

void Functionalities::CreateCarsAndBikes()
{
    m_data.emplace_back(new Car("c1",780000.0f,6));
    m_data.emplace_back(new Car("c2", 120000.0f,5));

    m_data.emplace_back(new Bike("B1",56000.0f));
    m_data.emplace_back(new Bike("b2",79000.0f));
}

void Functionalities::FindAverageCost()
{
    if(m_data.empty()){
        std::lock_guard<std::mutex> lk(mt);
        std::cerr<<"The data is empty!!";
    }
    float total {0};
    for(const VrType v : m_data){
        std::visit([&](auto&& val){total += val->price();},v);
    }
    if(!m_data.empty() && total !=0){
        std::lock_guard<std::mutex> lk(mt);
        std::cout<<total/m_data.size()<<"\n";

    }
    else {
        std::cerr<<"No data found\n";
    }
}

std::optional<VrType> Functionalities::ReturnMatchingInstance(std::string id)
{
    if(m_data.empty()){
        std::lock_guard<std::mutex> lk(mt);
        std::cerr<<"The data is empty!!";
    }
    bool match_found{false};
    std::optional<VrType> result{std::nullopt};
    for(const VrType v : m_data){
        std::visit([&](auto&& val){if(val->id() == id ){result = v; match_found = true;};},v);
        if(match_found){
            break;
        }
    }
    return result;
    // if(!m_data.empty() && match_found){
    //     return result;
    // }
    // else if(!m_data.empty() && !match_found){
    //     std::cerr<<"No matching data found\n";
    // }
}

void Functionalities::DisplayInsuranceAmount()
{
    if(m_data.empty()){
        std::lock_guard<std::mutex> lk(mt);
        std::cerr<<"The data is empty!!";
    }
    for(const VrType v : m_data){
        std::visit([&](auto&& val){std::cout<<val->InsuranceAmount() << "\n";},v);
    }
}

std::optional<unsigned short> Functionalities::FindSeatCountForGivenId(std::string id)
{
    if(m_data.empty()){
        std::lock_guard<std::mutex> lk(mt);
        std::cerr<<"The data is empty!!";
    }
    bool match_found{false};
    std::optional<unsigned short> result {std::nullopt};
    for(const VrType v: m_data){
        if(std::holds_alternative<Car*>(v)){
            Car* temp = std::get<0>(v);
            
            result= temp->seatCount();
            match_found = true;
        }
    }
    
    if(!m_data.empty() && !match_found){
        std::lock_guard<std::mutex> lk(mt);
        std::cerr<<"No data found\n";
    }
    return result;

    // return std::optional<unsigned short>();
}

void Functionalities::MapThread()
{
    m_threads.emplace_back(Functionalities::DisplayInsuranceAmount);
    m_threads.emplace_back(Functionalities::FindAverageCost);
}

void Functionalities::JoinThread()
{
    for(std::thread& th : m_threads){
        if(th.joinable()){
            th.join();
        }
    }
}

void Functionalities::Deallocate()
{
    for(VrType v:m_data){
        std::visit([](auto&& val){delete val;},v);
    }
}
