#include <iostream>
#include <thread>
#include <mutex>
#include<list>

//Singleton : A class whcih can be instantiated only once i.e., only  on object of this class can be present at any point in the application

using threadContainer = std::list<std::thread>;



class Bank
{
private:

    int32_t m_amount {1000};
    std::mutex mt;
    
    static Bank* m_instance_ptr;
    // static 

    //static data members of a clss canot be instantiated by the class
    //static member can be only modified by static member of the class only

    Bank() = default;
    Bank &operator=(const Bank&) = delete;
    Bank &operator=(const Bank&&) = delete;
    Bank(const Bank&)=delete;
    Bank(Bank&&)= delete;
    Bank(int32_t amount) : m_amount{amount} {}

public:
    
    ~Bank() = default;
   

    void Deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            // creating an delay in the output
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount += 10;
            mt.unlock();
        }
    }

    void Withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount -= 10;
            mt.unlock();
        }
    }

/*
    if the pionter exists, it means that the object off this calss is already present. As per rules of Singleton patter, new object cannot be created;

    So, thake the amount value given by the user. Update it in the existing object. return this same object's pionter to the user


    if pointer is null, it means no object currently exists in the system for this calss.  So a new instance can be created. Take "val" provided by the user to construct a new object on the heap and return its pointer.
*/

    int32_t amount() const { return m_amount; }
    static Bank* getInstance(int val){
        if(m_instance_ptr){
            m_instance_ptr -> setAmount(val);
            return m_instance_ptr;
        }
        else {
            m_instance_ptr = new Bank(1000); // constructor is called
            return m_instance_ptr;
        }
    }

    void setAmount(const int32_t &amount) { m_amount = amount; }
};

//static data members
Bank* Bank::m_instance_ptr {nullptr};

void CreateThreads(threadContainer& threads, Bank& b1){
    threads.emplace_back(&Bank::Deposit, &b1);
    threads.emplace_back(&Bank::Withdraw, &b1);
}

void joinThreads(threadContainer& threads){
    for(std::thread& th: threads){
        if(th.joinable()){
            th.join();
        }
    }
}

void DisplayFinalAmount(Bank& b1){
    std::cout<<"Final amount is : "<<b1.amount()<<"\n";
}

int main()
{
    // Bank b1{1000};

    Bank * ptr = Bank::getInstance(1000);

    threadContainer threads{}; //blan list
    CreateThreads(threads,*ptr);
    joinThreads(threads);
    DisplayFinalAmount(*ptr);
    
    delete ptr;
    // std::thread t1{&Bank::Deposit, &b1};
    // std::thread t2{&Bank::Withdraw, &b1};

    // t1.join();
    // t2.join();

    // std::cout << "The amount is :" << b1.amount() << "\n";
}