/*
    parallel process data with multiple thread
*/

/*

*/

#include<iostream>
#include<list>
#include<thread>
#include<functional>
#include<mutex>

using ThreadContainer = std::list<std::thread>;
using DataContainer = std::list<int16_t>;
using functionWrapper = std::function<void(int32_t)>;

std::mutex mt;

void mapThreads(ThreadContainer& threads, const DataContainer& data, functionWrapper fn){
    // auto itr = data.begin();

    // for(std::thread& th:threads){
    //     th = std::thread{ fn, *itr++};

    // }
    for(int32_t i : data){
        threads.emplace_back(fn,i);
    }
}

//threads cannot be const 
void joinThreads( ThreadContainer& threads){
    for(std::thread& th : threads){
        if(th.joinable()){
            // mt.lock();
            th.join();
            // mt.unlock();
        }
    }

}

// void Display(){


// }

int main(){

    ThreadContainer threads {};
    DataContainer data{10,20,30,40};
    auto fn = [](int32_t number){ 
        mt.lock();
        std::cout<< number * number<<"\n" ;
        mt.unlock();
    };

    mapThreads(threads, data, fn);
    joinThreads(threads);

}

