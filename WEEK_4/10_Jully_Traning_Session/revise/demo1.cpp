/*
    thread : Isolated unit of instructions
    executing in memory
*/
#include<iostream>
#include<vector>
#include<thread>

#include<mutex>

std::mutex mt;

class Dummy
{
private:
    
public:
    Dummy(/* args */) {}
    ~Dummy() {}
    void displayFactorial(unsigned int val){
        if(val == 1 || val == 0){
            std::lock_guard<std::mutex> lk(mt);
            std::cout<<1<<"\n";
        }
        else {
            unsigned int result {1};
            for(unsigned int i =2;i<val;i++){
                result *= i;
            }
            std::lock_guard<std::mutex> lk(mt);
            std::cout<<result<<"\n";
        }

    }

    static void MultiplyBy100(int number){
        std::lock_guard<std::mutex> lk(mt); 
        std::cout<<number * 100 <<"\n";
    }


};

void Square(int number){
    std::lock_guard<std::mutex> lk(mt);
    std::cout<<number*number<<"\n";
}

auto fn = [](int number){std::lock_guard<std::mutex> lk(mt);std::cout<<number*number*number;};

void Mapthreads(std::vector<std::thread>& threads){
    threads[0]=std::thread(&Square,10);
    threads[1] = std::thread(fn,10); //fn is not a function it is an object.
    threads[2]=std::thread(Dummy::MultiplyBy100,3);
    Dummy d1{};
    threads[3]=std::thread(&Dummy::displayFactorial, &d1, 4);
}

void JoinThreads(std::vector<std::thread>& threads){
    for(std::thread& th:threads){
        if(th.joinable()){
            th.join();
        }
    }
}

int main(){
    
    std::vector<std::thread> threads {4};
    Mapthreads(threads);
    JoinThreads(threads);
   
}