#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<list>
#include<thread>
#include<mutex>
#include<future>
#include "Functionalities.h"
#include"Engine.h"
#include<functional>
#include<memory>

#include<unordered_map>

using EnginePtr= std::shared_ptr<Engine>;
using DataContainer = std::unordered_map<std::string, std::shared_ptr<Engine>>;
using Container = std::list<std::shared_ptr<Engine>>;
using Predicate = std::function<bool(const EnginePtr&)>;

void createObjects(DataContainer& engine);

/*
    returnMatchingContainer
    input Data constainer reference, function wrapper for predicate
    output:data container  
*/
std::optional<Container> ReturnMatchingContainer(const DataContainer& engine, const Predicate& Fn);

/*
    input: data and fn
    output bool
*/

bool AtleastOneInstanceMatching(const DataContainer& data, const Predicate& fn);

/*
    average
*/

int AverageEngineCC(const DataContainer& data);



// void createObjects()

// class Functionalities
// {
// private:
//     static DataContainer m_data;
//     static std::mutex mt;
//     static Container ptr;
// public:

//     Functionalities() = delete;
//     Functionalities(const Functionalities&)= delete;
//     Functionalities& operator=(const Functionalities&) = delete;
//     Functionalities(Functionalities&&)=delete;
//     Functionalities& operator = (Functionalities&&) = delete;
//     ~Functionalities() = default;
    
//     void createObjects();

//     void 
// };


#endif // FUNCTIONALITIES_H
