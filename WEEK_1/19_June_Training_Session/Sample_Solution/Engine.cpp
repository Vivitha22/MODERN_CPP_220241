#include "Engine.h"


Engine::Engine(int id, int power, float torque) : m_id{id}, m_horsepower{power}, m_torque{torque}{
        
}

Engine::~Engine(){
    std::cout<<"The object with id :"<<m_id<<" is delete\n";
}
