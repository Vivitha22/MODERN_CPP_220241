/*
    thread : Isolated unit of instructions
    executing in memory
*/
#include<iostream>
#include<vector>
#include<thread>
#include<future>
#include<mutex>

std::mutex mt;

class Dummy
{
private:
    
public:
    Dummy(/* args */) {}
    ~Dummy() {}
    int displayFactorial(unsigned int val){
        // int result {0};
        if(val == 1 || val == 0){
            // std::lock_guard<std::mutex> lk(mt);
            return 1;
        }
        else {
            unsigned int result {1};
            for(unsigned int i =1;i<=val;i++){
                result *= i;
            }
            return result;
        }

    }

    static int MultiplyBy100(int number){
        return number * 100;
    }


};

int Square(int number){
    return number*number;
}

auto fn = [](int number){return number*number*number;};



void CollectInDataContainer(std::vector<std::future<int>>& container){
    int n1{2};
    Dummy d1{};
    container.emplace_back(std::async(Dummy::MultiplyBy100,2));
    container.emplace_back(std::async(&Dummy::displayFactorial,&d1,5));
    container.emplace_back(std::async(&Square,7));
    
    container.emplace_back(std::async(fn,n1));
}

void display(std::vector<std::future<int>>& vector){
    for(std::future<int> & v:vector){
        std::cout<<v.get()<<"\n";
    }
}

int main(){
    // int n1{10};
    // Dummy d1{};
    std::vector<std::future<int>> results{};
    // std::future<int> res1 = std::async(&Square,10);
    // std::future<int> res2= std::async(fn, std::ref(n1));
    // std::future<int> res3 = std::async(Dummy::MultiplyBy100,10);
    // std::future<int> res4 = std::async(Dummy::displayFactorial,&d1,10);
    CollectInDataContainer(results);
    display(results);


    

   
}