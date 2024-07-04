/*
    elision: no t do something, not perorm something, ingore/ avoid something

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
    Data(Data&&)=default;
    Data& operator=(const Data&)=delete;
    Data& operator=(Data&&)=delete;
    ~Data() = default;
    explicit Data(int val): m_value{val} {}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }

    
};

Data Creater(){
    return Data{100};
}

// void absorber(Data d1){
//     std::cout<<d1<<"\n";
// }

//or

Data absorber(Data d1){
    std::cout<<d1<<"\n";
    return d1;
}

int main(){
    // absorber( Creater() );

    //or

    Data obj =  absorber(Data{100});

    std::cout<<"Object is in main : "<<obj <<"\n";
}