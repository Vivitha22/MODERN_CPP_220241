#include<iostream>
#include<stack>

void reverse(std::stack<int>& s,unsigned int size){
    // for(int i=0;i<size;i++){
    //     int v;
    //     std::cout<<"Enter the v : ";
    //     std::cin>>v;
    //     s.emplace(v);

    // }
    std::cin>>s;
    for(int i=0;i<size;i++){
        std::cout<<s.top()<<"\n";
        s.pop();
    }
}

void reverseString(std::stack<std::string>& data){
    std::cin>>data;

}
int main(){

    std::stack<int> s;
    std::stack<std::string> str;
    unsigned int size{5};
    reverse(s,size);
    reverseString(str);
    // s.emplace(1);
    // s.emplace(3);
    // s.emplace(6);

    // std::cout<<s.top()<<"\n";
    // s.pop();

    // std::cout<<s.top()<<"\n";
    // s.pop();

    // std::cout<<s.top()<<"\n";
    // s.pop();

    // for(int i=0;i<size;i++){
    //     int v;
    //     std::cout<<"Enter the v : ";
    //     std::cin>>v;
    //     s.emplace(v);

    // }
    // for(int i=0;i<size;i++){
    //     std::cout<<s.top()<<"\n";
    //     s.pop();
    // }
}
