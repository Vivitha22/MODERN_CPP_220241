#include<iostream>
#include<thread>
#include<mutex>

// std::mutex mt{};

class MathOperation
{
private:

    std::mutex mt{};//you never set value to mutex you just initizalize
    int32_t m_value {0};

public:
    MathOperation(const MathOperation&) = delete;
    MathOperation()=default;
    MathOperation(MathOperation&&)= delete;
    MathOperation& operator = (const MathOperation&)=delete;
    MathOperation& operator = (const MathOperation&&)=delete;
    MathOperation(int32_t val):m_value{val} {}
    ~MathOperation()=default;

    void square(){
        mt.lock();
        std::cout<<"ID : of the thread square : "<<std::this_thread::get_id()<<"\n";
        std::cout<<"Square of "<<m_value<<" is : "<<m_value * m_value<<"\n";
        mt.unlock();
    }
    
    int32_t addition(int32_t other){
        mt.lock();
        std::cout<<"ID : of the thread addition : "<<std::this_thread::get_id()<<"\n";
        mt.unlock();

        return m_value + other;
    };
    

    //paren paren operator
    int64_t operator()(){
        mt.lock();
        std::cout<<"ID : of the thread operator : "<<std::this_thread::get_id()<<"\n";
        mt.unlock();
        return m_value * m_value * m_value;
    }
};

int main(){

    MathOperation m1{100};
    // std::thread t1 {&MathOperation::square, MathOperation{10}};
   
    std::thread t1 {&MathOperation::square, &m1};

    //you cannot capture return values from a function when executing them via std::thread

    std::thread t2 { std::ref(m1) } ; //thread created by a functor object
    std::thread t3 {&MathOperation::addition, &m1,100} ;

    //what ever you give in the thread the first parameter is always funciton and compliler take it as callables

    t1.join();
    t2.join();
    t3.join();

    //note : t2 and t3 output will get discarded. No way to capture it 

    //note all parameters passed to std::thread constructor are taken as "call by value"

}

//to avoid the defaulting the copy use functional wrapper std::ref


//thread can't capture return values from the function when executing them via std::thread