#include<iostream>
#include<unordered_map>
#include"Employee.h"
#include<functional>

using Predicate = std::function<bool()>;

using Container = std::unordered_map<unsigned int, Employee>;


//cpp17
void DisplayMapUsingStructureBinding(const Container& data){
    for(auto& [k,v] : data)//syntactic sugar
    { 
        std::cout<<"key is : "<<k << " & Value is : "<< v<<"\n";
    }
}

void CreateObject(Container& data){
    //the 101 is used 2s because we are using it as id and also as key for the map
    //          [key],   <--------------[value]---------------->
    //data.emplace(101,    101, "Vivitha" , 20000.0f , 28 , 11.1f);


    data.emplace(
        std::piecewise_construct,//construct by considering by 2 places
        std::forward_as_tuple(101),//first piece is a tuple of 1 key
        std::forward_as_tuple(101, "Vivitha" , 20000.0f , 28 , 11.1f) // second piece is a tuble of 5 items
    );
    data.emplace(
        std::piecewise_construct,//construct by considering by 2 places
        std::forward_as_tuple(102),//first piece is a tuple of 1 key
        std::forward_as_tuple(102, "Hari" , 30000.0f , 38 , 31.1f) // second piece is a tuble of 5 items
    );
    data.emplace(
        std::piecewise_construct,//construct by considering by 2 places
        std::forward_as_tuple(103),//first piece is a tuple of 1 key
        std::forward_as_tuple(103, "Hari" , 40000.0f , 48 , 41.1f) // second piece is a tuble of 5 items
    );
}

void FindAverageSalary(const Container& data){
    /*
        for every pair of key and value,

        go to value section and use the ferrer to fetch salary,

        add salary to total

        at the end of for loop, divide total by size of hash table
    */
   float total{0.0f};
    for(auto& [k,v] : data){
        total+= v.salary();
    }
    std::cout<<total/data.size()<<"\n";
}

void FindEmployeeById(const Container& data, unsigned int key){
    auto itr = data.find(key);
    if(itr == data.end()){
        std::cerr<<"Employee with given key : "<< key <<" is not found\n";
    }
    else {
        std::cout<<itr->second<<"\n";
    }
}

void FilterEmployeeByPredicate(const Container& data, Predicate& fn){
    // if(fn( reinterpret_cast<const Employee&>(v))){

    // }
    /*
        do not apply filter on dey ondition is bassed on objects value
    */

    for(const std::pair<unsigned int,Employee>& )
}
int main(){
    Container data;
    CreateObject(data);
    DisplayMapUsingStructureBinding(data);
 

}