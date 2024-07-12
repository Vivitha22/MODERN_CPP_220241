#include<iostream>
#include<unordered_map>

//names of procts attached to a numeric serial number for each

using Container = std::unordered_map<unsigned int, std::string>;

//iterator : idea of going from one element to other without worrying about the actual process involved

//old cpp way

// if you want to use iteratot
void DisplayMapUsingIterators(const Container& data){
    for(auto itr = data.begin();itr != data.end() ;++itr){
        std::cout<<"Key is : "<< itr->first << " and value is "<<itr->second<<"\n";
    }
}

//cpp17
//if you want to do end to end
void DisplayMapUsingStructureBinding(const Container& data){
    for(auto& [k,v] : data)//syntactic sugar
    { 
        std::cout<<"key is : "<<k << " & Value is : "<< v<<"\n";
    }
}

//use this if you want to return a pair
void DisplayMapUsingPair(const Container& data){
    for(const std::pair<unsigned int,std::string>& p: data){
        std::cout<<"Key is : "<< p.first << " and value is "<<p.second<<"\n";
    }
}

int main(){
    Container data{
        //pare of 1 key attached 1 value.
        {101,"Steering Wheels"},
        {102, "Alloy wheels"},
        {103,"Smart Mirrors"},
        {104,"360 Camera setup"}
    };
    DisplayMapUsingIterators(data);
    DisplayMapUsingStructureBinding(data);
    DisplayMapUsingPair(data);

}