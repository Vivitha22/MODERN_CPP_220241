/*
    a)
    execute tasks in asynchronous mode

    b) it is a thread that acn also catch a return value so could be used in cpp to execute value returning function in  a separate thread as well.
*/

#include<iostream>
#include <future>//this is cpp11 allows you to do in async thread

int64_t Magic(int32_t number){
    return number * number;
}

int main(){
    std::future<int64_t> ans = std::async( &Magic,  10);//as soon as this line is executed the thread is created and starts the work;
    //if thread is still executing, mail will get blocked at this line till completion of magic function.
    std::cout<<ans.get()<<"\n";//this get() function fetchs the returned value from the async thread.

}