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
int main(){
    int32_t x {10};
    char grade {'A'};
    char* ptr1 = (char*)malloc(4);
    char* ptr2 = (char*)malloc(1);

    std::unique_ptr<int> ptr1  {  (int*)malloc(4)}; //since its object we can create objects
    std::unique_ptr<int> ptr2 {new int()};
    std::unique_ptr<char> ptr3 {(char*)malloc(1)}  ;

    if(true){
        std::cout<<*ptr1<<"\n";
    }
    else{
        // throw
    }
    std::unique_ptr<Data> ptr { new Data{1000} };

}

/*
    stack main functions


    0x104H    grade 'A'
    0x100H    x    10
*/
/*
    void CAlculateResult(input value){
        //allocate something on head
        ptr = heap memory address

        if(value == comdition){
            do something with ptr
            //action to do

            if(consdition1){
                take action
            }
            else if(condition2){
                throw exception
            }
            else if(condition3){
                throw exception
            }
            else if(condition4){
                throw exception
            }
            else if(condition5){
                throw exceptionkt
            }
            else{
                do something
            }
        }


        else{
            delete ptr;
            throw exception
        }
    }
*/

/*
    Smart pointers ---->
    Shared pointer --->one resourse is connected to all the 
    unique pointer ---->
    weak pointer
*/