#include<iostream>
#include<functional>

class Data
{
private:
    int m_value {0};

public:
    Data() = default;
    ~Data() = default;
    Data(Data&&)=delete;
    Data& operator=(Data&&)= delete;
    Data(const Data&)=delete;
    Data operator=(const Data&)= delete;

    Data(int val):m_value{val} {}

    void displayReading(int factor){
        std::cout<<m_value * factor<<"\n";
    }

    static void Display(int times){
        std::cout<<"Hello world "<< times << " Times"<<"\n";
    }

};

int main()
{
    Data obj {18}; //m_value is 18
    
    obj.displayReading(100); //100 is the factor
    
    //or
    
    auto fn= std::bind(&Data::displayReading, &obj, 100); //calling the displayReading function, passing the obj reference, the value for the factor
    fn(); //obj.displayReading(100);

    // to call a static function 
    Data::Display(10); // hello world  10 times

    //or
     
    auto binded_static_funciton = std::bind(&Data::Display,  10);
    binded_static_funciton();

}

/*
    for non-static member funcitons :
        a)object address is mandatory
        b) it must be the first argument agter specifying the ame of function in bind function
        c) you "must" use '&' symbol with the name of the member function in bind

    for static member functins:
        a) no object involved so no address required
        b) you "SHOULD NOT" use '&' symbol with the name of the function
*/

/*
    aggregation, composition, inheritance with 
*/