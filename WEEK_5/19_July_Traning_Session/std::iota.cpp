#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

/*
    v : {0,0,0,0}

    desired result : v:{19,20,21,22,23}
*/

int main(){

    std::vector<int> data(5);
    std::iota(
        data.begin(),
        data.end(),
        19
    );

    std::for_each(data.begin(),data.end(), [] (int val){std::cout<<})
}