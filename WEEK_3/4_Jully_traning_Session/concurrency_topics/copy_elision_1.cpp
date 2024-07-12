/*
    elision: not do something, not perform something, ingore/ avoid something

    Gurateed copy Elision : cpp17
    This will give you the guranty that copy is not allowed, it is done by the compiler automatically
    it is an optimization feature


*/

#include <iostream>
class Data
{
private:
    int m_value {0};
public:
    Data() = default;

    Data(const Data&)= delete;
    Data(Data&&)=delete;
    Data& operator=(const Data&)=delete;
    Data& operator=(Data&&)=delete;
    ~Data() = default;
    explicit Data(int val): m_value{val} {}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }

    
};

void magic(Data d1){
    std::cout<<d1<<"\n";
}

int main(){
    Data d1{100};


    
    /*
        this will work, because the compiler does the implicit comversion

        THIS IS BAD CODE BECAUSE THE COMPILER CONVERTS THE DATA OBJECT TO INT-------->THIS SHOULD NOT HAPPEN 

            --->TO SOLVE THIS USE EXPLICIT IN THE PARAMATERAIZED constructor 
    */
    // magic(d1); ->This will not work beacuse the copy is diabled
    // magic(99); // ---->This will not work beacuse conversion is disabled (explicit)

    magic(Data {100}); //-->uniform initialization
    //THe above line works beacause an rvalue of type Data is used to initialize an object of type Data. 
    //Complier simply refactors/,pdofoed tje cpde as Data d1{100}
}