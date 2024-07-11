#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Car.h"
#include"Bike.h"

#include<variant>
#include<thread>
#include<mutex>
#include<list>
#include<future>
#include<optional>

using VrType = std::variant<Car*,Bike*>;
using Datacontainer = std::list<VrType>;
using ThreadContainer = std::list<std::thread>;

class Functionalities
{
private:
    static Datacontainer m_data;
    static ThreadContainer m_threads;
    static std::mutex mt;
public:
    
    Functionalities()=delete;
    Functionalities(const Functionalities&)= delete;
    Functionalities& operator=(const Functionalities&)= delete;
    Functionalities(Functionalities&&)=delete;
    Functionalities& operator=(Functionalities&&)=delete;
   
    ~Functionalities() =default;

    static void CreateCarsAndBikes();

    static void FindAverageCost();
    static std::optional< VrType> ReturnMatchingInstance(std::string id);
    static void DisplayInsuranceAmount();

    static std::optional<unsigned short> FindSeatCountForGivenId(std::string id);

    static void MapThread();
    static void JoinThread();
    static void Deallocate();

};

#endif // FUNCTIONALITIES_H
