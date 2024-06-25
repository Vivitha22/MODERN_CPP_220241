#include<iostream>

class Vehicle
{
private:
    std::string m_id {""};
    std::string m_modelname{""};
public:
    Vehicle() = delete;
    ~Vehicle() = default;

    /*
        this is a vehicle constructor that takes one const lvalue reference to a Vehicale as as parameter
    */
    Vehicle(const Vehicle& other) = delete;
    Vehicle(std::string id, std::string name): m_id{id},m_modelname{name} {}
    
};

int main(){
    Vehicle v1{"101", "Dzire"};

    // Vehicle v2{v1};

    //copy construction means copying to a variable  created for first time
    //copy assignment means overwritting the already existing variable

    Vehicle v3 = v1; // copy construction

    Vehicle v4{};
    v4=v1; // copy assignment 


}