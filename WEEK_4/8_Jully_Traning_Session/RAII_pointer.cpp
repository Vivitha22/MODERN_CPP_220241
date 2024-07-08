/*
    while doing the program the heal allocations is made.  Accourding to head the deletion should be done manually, but we cant delete everytime in the program in every condition .

    So to overcome this we use RAII_Pointer in the cpp 

    the owner of the resource is tracked, if it is gone the associated pointer will also be gone 

    this allow you to release the memory with

    accq
*/

//list
// #include<iostream>
// #include<list>

// void CrateData(std::list<int> & data)
// {   
//     data.emplace_back(10);
//     data.emplace_back(20);
// }

// void calculateTotal(std::list<int> & data){
//     if(data.empty()){
//         throw std::invalid_argument("Empty data");
//     }

//     int total{0};
//     for(int val:data){
//         total += val;
//     }
//     std::cout<<"Total is" << total <<"\n";
// }

// void PrintFirstElement(std::list<int> & data){
//     if(data.empty()){
//         throw std::invalid_argument("Empty data");
//     }
//     std::cout<<data.front()<<"\n";
// }

// int main(){
//     std::list<int> data;
//     CrateData( data);
//     calculateTotal( data);
//     PrintFirstElement( data);
// }


//c-type array
#include<iostream>
#include<list>
#include<memory>

void CrateData(std::shared_ptr<int[]> data)
{   
    data[1]=10;
    data[2]=20;
}

void calculateTotal(std::shared_ptr<int[]> data,int size){
   

    int total{0};
    for(int i=0;i<size;i++){
        total += data[1];
    }
    std::cout<<"Total is" << total <<"\n";
}

void PrintFirstElement(std::shared_ptr<int[]> data,int size){
    // if(data.empty()){
    //     throw std::invalid_argument("Empty data");
    // }
    std::cout<<data[0]<<"\n";
}

int main(){
    // int* arr  = new int[2];
    std::shared_ptr<int[]> arr {new int[2]};
    CrateData(arr);
    calculateTotal(arr, 2);
    PrintFirstElement(arr, 2);
}