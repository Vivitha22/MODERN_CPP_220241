/*
    Terminologies :

       1} CPU:set of hardware responsible for executing tasks in a computing system
 
       2) System : Any computing device

       3) processor : Hardware chip (made of silicon) designed for executing instructions given by the user of the computer

       eg:intel 17-1265U

       4) socket : point on the motherboard where processor is connected

       5) core : Every processor is divided interbally into units called as "cores" 
       Each core can execute instructions from one "process" at any given time;

       6)process : a running task on the system


*/

//SINGLE THREAD SYNCRONISE 

#include<iostream>
#include<vector>
#include<functional>
#include<thread>
#include<mutex> // original, binary semaphore

std::mutex mt; //mutex prevents the race conditions

//it is not allowed to copy mutex 


using operation = std::function<void(int number)>;
// using array = std::array<int,10>;

// array result {0};


void Adaptor( operation   fn   , const std::vector<int> &data){
    // int k=0;
    for(int val:data){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        fn(val); // apply function on a single item, repate this in aloop
    }
}

//access to the shared resource is the critical section
void square(int number){

    mt.lock(); // as for the permission to access the cout
    std::cout<< number*number<<"\n";  //critical section
    mt.unlock();//release the lock when done
}

//order execution is not guaranteed because we dont't know which thread will execute first If you want your output in ordered way, then don'e use thread

int main(){
    auto cube_fn = [](int number){
        mt.lock();
        std::cout<<number * number*number<<"\n";
        mt.unlock();
    };

    // Adaptor(square, std::vector<int> {1,2,3,4,5});
    // Adaptor(cube_fn, std::vector<int> {1,2,3,4,5});

    //executes adaptor function by using square function vector of values as its pareameters

    std::thread t1{&Adaptor,&square, std::vector<int>{1,2,3,4,5}};

    std::thread t2{ &Adaptor, cube_fn, std::vector<int>{1,2,3,4,5}};
    t1.join(); //main canot procedd beyond this line unless t1 is terminated/completed
    t2.join(); // main cannnot proceed beyound linve 54 unless t2 is terminated/completed

    // for(int val:result){
    //     std::cout<<val<<"\n";
    // }

}