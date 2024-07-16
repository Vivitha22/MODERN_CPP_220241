/*
    10, 20 30 40

    I would like to data continously / I want to access previous and next elemetns of a certain element in the fastest time.

    A machanism to say to access a feature or something
*/

#include "Employee.h"
#include<queue>
#include<memory>

using EmployeePtr = std::shared_ptr<Employee>;
using DataContainer = std::queue<EmployeePtr>;

void CreateEntriesForQueue(DataContainer& data){
    data.emplace(std::make_shared<Employee>(101,"Vivitha", 2000.0f,22,2.0f));
    data.emplace(std::make_shared<Employee>(102, "Kavitha", 4000.0f,25,25.0f));
    data.emplace(std::make_shared<Employee>(103,"Vijayakumar", 6000.0f,27.0f,26.0f));
}
/*
                            (101,"Vivitha", 2000.0f,22,2.0f));
                                                                    102, "Kavitha", 4000.0f,25,25.0f
                                                                                                        103,"Vijayakumar", 6000.0f,27.0f,26.0f
                            ^                                       ^                                      ^
                            |                                       |                                      |
    start of queue  -----> [[0x100H]]                            [[0x296H]]                             [[0x876H]]    --->End of the queue

*/

int main(){
    DataContainer employees{};
    CreateEntriesForQueue(employees);

    /*
        Queue is a FIFD data structure.
        Insertion of items at one end and retrieval from the start
    */

    std::cout<<*employees.front()<<"\n";


    /*
        We can check size
    */

    std::cout<<employees.size()<<"\n";

    /*
        We can obly read/fetch the data at the end of the queue
    */
    std::cout<<*employees.back()<<"\n";
}