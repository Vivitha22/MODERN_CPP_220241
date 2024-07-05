#include<iostream>

void Display(char grade){
    std::cout<<grade<<"\n";
}

void Demo(int n1, std::string name){
    std::cout<< n1 <<"\t"<<name<<"\n";
}

void temp(float n1, int* ptr, std::string name, char&& grade,const bool& flag){
    std::cout<<n1<<"\t"<<*ptr<<"\t"<<name<<"\t"<<grade<<"\t"<<flag<<"\n";
}

int main(){
    Display("A"); // this is error because character should be in the single quote::-->  fix this by sending the character in single quote

    Demo("abc", 10); //this will give an error because the values are passed incorrectly
    //                 the function definition is int,string but we are passing string, id
    //                  to solve just place the cursor on the function it will give you the parameters of the function 

    /*
        Demo is an void function which has 2 parameters of type non-const  integer value, and non-const string value
        The function prints the integer and the string which is passed by the user in the main function
        this will not return any value because it is void type  
    */
   std::string val {"vivi"};
    bool flag {true};
    char grade {'A'};
    temp(10.21f, new int(10),val,'A', flag);
    temp(10.21f, new int(10),val,grade, flag); // this is error because the input is char&& which is a rvalue but ur passing an lvalue

    //double '&' means rvalue reference 
    //const lvalue means reference, const rvalue means assigned
}