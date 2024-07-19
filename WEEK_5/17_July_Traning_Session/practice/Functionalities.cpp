#include "Functionalities.h"


void createObjects(DataContainer &engine)
{
    // engine.emplace_back(new Engine("101",12,20.2f,23,EngineType::HYBRID));
    // engine.emplace_back(new Engine("102",5,35.02f,55,EngineType::ALTERNATE_FUEL));
    // engine.emplace_back(new Engine("103",87,54.0f, 654,EngineType::ICE));
    // engine.emplace_back(new Engine("104",47,52.2f,73,EngineType::HYBRID));
    // engine.emplace_back(new Engine("105",789,22.02f,25,EngineType::ALTERNATE_FUEL));4


//or
    // std::shared_ptr<Engine> sptr(std::make_shared<Engine>("105",789,22.02f,25,EngineType::ALTERNATE_FUEL));

//or

    // engine.emplace_back(std::make_shared<Engine>("105",789,22.02f,25,EngineType::ALTERNATE_FUEL));

    engine.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("101"),
        std::forward_as_tuple(std::make_shared<Engine>("101",12,20.2f,23,EngineType::HYBRID))
    );
    engine.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("102"),
        std::forward_as_tuple(std::make_shared<Engine>("102",5,35.02f,55,EngineType::ALTERNATE_FUEL))
    );
    engine.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("103"),
        std::forward_as_tuple(std::make_shared<Engine>("103",87,54.0f, 654,EngineType::ICE))
    );
    engine.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("104"),
        std::forward_as_tuple(std::make_shared<Engine>("104",47,52.2f,73,EngineType::HYBRID))
    );
    engine.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("105"),
        std::forward_as_tuple(std::make_shared<Engine>("105",789,22.02f,25,EngineType::ALTERNATE_FUEL))
    );
}


std::optional<Container> ReturnMatchingContainer(const DataContainer& engine, const Predicate& fn)
{
    bool is_input_empty {false};
     if(engine.empty())
    {
        
        std::cerr<<"Data container is empty";
        is_input_empty = true;

    }
    // for(std::shared_ptr<Engine> val:engine)
    Container result {};
    for(auto& [k,val] :engine)
    {
        if(fn(val)){

            result.emplace_back(val);
        }
    }
    if(!is_input_empty && result.empty()){
        // std::cout<<"The container is empty";
        return std::nullopt;
    }
    else if(!is_input_empty && !result.empty()){
        return result;
    }
    else{
        return std::nullopt;
    }
    
}


bool AtleastOneInstanceMatching(const DataContainer &data, const Predicate& fn)
{
    if(data.empty())
    {
        std::cerr<<"Data container is empty";
    }
    bool Instancefound {false};
    for(auto& [k,val]: data){
        if(fn(val)){
            // Instancefound = true;
            return true;
        }
    }
    return false;
}

int AverageEngineCC(const DataContainer &data)
{
    if(data.empty())
    {
        std::cerr<<"Data container is empty";
    }
    int total {0};
    for(auto& [k,val]:data){
        total += val->engineHorsepower();   
    }
    // std::cout<<total/data.size();
    return total/data.size();
}