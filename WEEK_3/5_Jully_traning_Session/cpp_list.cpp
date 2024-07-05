#include<iostream>
#include<variant>
#include<list>

using Datacontainer = std::list<std::string>;

int main(){
    Datacontainer data {10,20,30};    //this is an error cause we declared list of strings but we gave a list of integers
     

}