#include<iostream>
#include<unordered_set>

int main(){
    std::string data{};
    std::cin>>data;

    std::unordered_set<char> s {data.begin(), data.end(),data.size() };

    for(char c:s){
        std::cout<< c <<"\t";
    }
}