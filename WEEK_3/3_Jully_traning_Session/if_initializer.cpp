/*
    bool definition fn(){
        ////
    }

    main(){
        bool flag fn{}
        if(flag){
            /////
        }   
        else{
            ////
        } /////flag should be erased at the end of this line!

        //flag is gone
    }
*/


#include<iostream>

bool CheckDivisibilityBy3(int32_t num){
    return num%3 == 0;

}

int main(){
    int32_t n1 {10};

/*
    we are doing this flag because we dont want the flag to be in scope after the if condition so if you initialize it in the if loop,, thn it willbe discarded immidiately after the scope is out of if condition
*/

  //if flag variable is initialized and then ; flag is also true
    if( bool flag = CheckDivisibilityBy3(n1) ; flag){
        std::cout<<"The number is divisible by 3 ";
    }
    else{
        std::cerr<<"The flag is set at : "<<std::boolalpha<<flag<<"\nNumber is not divisible\n";
    }
    // std::cout<"Cannot access flag now:"<<flag; //this line throw error
}