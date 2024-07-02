/*
    amount = 1000;
    100 widthraw operations(10 rs each)
    100 deposit operations(10rs each)

    after 200 transcation completed, what is th expected final amount:


        write in one thread
*/

#include<iostream>
#include<thread>
#include<mutex>

std::mutex mt;
int32_t amount {1000}; // shared value
// int32_t m_amount{0};



void Deposit(){
    for(int i=0;i<100;i++){
        //creating an delay in the output
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        mt.lock();
        amount += 10;
        mt.unlock();
    }
}

void Withdraw(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        mt.lock();
        amount -= 10;
        mt.unlock();
    }
}

int main(){

    //method 1:

    //synchronous sigle thread excecution : instruction n will start after n-1 is over

    // Deposit();
    // Withdraw();

    //Method 2:

    std::thread t1{&Withdraw};
    std::thread t2{&Deposit};

    t1.join();
    t2.join();
    
    std::cout<<"The amount is : "<<amount<<"\n";
    // std::cout<<"The amount is : "<<m_amount<<"\n";
}

// for((i=0;i<50;i++)); do time ./app; done