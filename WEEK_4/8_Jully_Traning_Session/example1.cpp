/*
    usecase 1) calculate square for 10 numbers

    10 std::thread objects to compute square of number of each 

    usecase 2) 

    5 operations are to be performed. all are independent(order of execution is not important). Exceture all 5 parallely
            a)one std::thread for each operation
            b)one async std::thread for each operation
            c) mix of std::thread and std::async

        all functions returning a value need to be executed via std::async, others via std::thread

   use case 3) 
    
        [producer - consumer problem]

        f1(producer) ----> data will be generated

        f2(consumer) ----> processing data obly after data is generated


        example : sensor detects collision and deployment of airbags!

        program to calll emergency()
*/

#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>


int32_t value{0};
std::condition_variable cv;
std::mutex mt;
bool inputReceived {false};

void Producer(){
    while(!inputReceived){
        std::cin>>value;
        if(value!=0){
            inputReceived = true;
        }
    }   

    /*
        data is produced
            1)user input has been accepted
            2) input must be above 5

        //send a signal!!!
    */

    std::lock_guard<std::mutex> lk{mt}; //this will be discared at the end of the function
    //this release accounding to the raii
    cv.notify_one(); //sends a signal
}

void Consumer(){
    //waiting for the signal!!
    /*
        scenario1 : consumer starts. consumer checks for condition if condition is false, I connot exit the function
    */
    std::unique_lock<std::mutex> ul{mt};
    //this is a wrapper which releases at the end or in the middle according to the condition.
    cv.wait(  ul  , [](){return inputReceived;}  );
    //this value cannot be computed before producer gives a signal!!!
    std::cout<<"Value squared is : " << value*value<<"\n";
}


int main(){
    //will launch producer
    std::thread t1{&Producer};

    //will launch consumer
    std::thread t2{&Consumer};

    std::cout<<"Main continous chilling! ask for 15 crors to fire employees advice !!! \n";
    std::cout<<"Main can literally do anything\n";

    t1.join();
    t2.join();

    std::cout<<"That's all. Boiii boiiiiiiiiiiiiiiiii";
}

/*
    3 perspectives

        a)I created t1 thread(producer)
        b)I created t2 thread(consumer)
        c)first cout
        d) secpnd cout
        e) t1 join
        f) t2 join
        g)goodbyee cout
        h)termibate app!

        Producer Perspective :
            a)Executed a loop. In the loop till m_input_received is true:
                1) took a input
                2) checked if input is greater > 5 , make flag true

            b) acquire a mutex so that nobody disturbs
            c) send a signal via notify_one().

*/