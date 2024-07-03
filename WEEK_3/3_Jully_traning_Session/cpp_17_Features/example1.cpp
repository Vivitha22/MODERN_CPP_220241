#include<iostream>
#include<vector>

#include<variant>

//variants :they are categorical types which allows "either or" principle of typing

int main(){
    int32_t n1 {100};
    std::string s1{"Vivitha"};
    std::variant<int32_t, std::string> vr;
    // std::vector<T> v1{n1,s1};

    vr=n1;// n1 is assigned to an variant

    std::cout<<"Variant is working\n";


    vr = s1;



    // vr = 41.45f;
}


/*

    vr = n1;
        int32_t      std::string    index_variable
    [     10      |   xxxxxxxxx   |        0         ] // 24bytes


    vr=n2;

        int32_t      std::string     index_variable
    [     10      |     {vivi}    |        1         ] // 24bytes

*/

//using variant, if you try to access a invalid location you will git "bad variant exception"
//when you use union, you will get "undefined behaviour"0