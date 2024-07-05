#include<iostream>
#include<memory> // cpp11 feature

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

/*
    resource : 4 bytes of memory on the heap used by the data object with value 100


*/

int main(){
    
    std::unique_ptr<Data> ptr4 { new Data{1000} };

    std::unique_ptr<Data> ptr5{ptr4};
}

