#include<iostream>
#include<functional>
#include<vector>
#include<stdexcept>

/*
    create an adoptor which accepts

    a) a data container of string values
    b) a function with the following signature
        i)input parameter : one string by lvalue reference
        ii) output : void
    
    Adoptor should be used to perform operations on sting values which are

        1) identify vowels
        2) print the last 3 characters of each string
        3) print the first non-vowel character of each string
*/

using container = std::function<void(const std::string&)>;
using datacontainer = std::vector<std::string>;

// void Adaptor(container fn, std::string& str, unsigned int size){
//     for( int i=0;i<size;i++){
//         if(fn(str[i])){
//             std::cout<<str[i];
//         }
//     }
// }

void Adaptor(container fn, datacontainer& data ){
    if(data.empty()){
        std::invalid_argument("Data is empty\n");//exit
    }
    for ( const std::string& st:data){
        fn(st); //findVowels
    }
}

void findVowels(const std::string& val){
    if(val == ""){
        std::cerr <<"Cant find any vowels\n";
        return ;
    }
    bool atleatonevowel=false;
    for(char c : val){
        if(c=='a' || c== 'A' || c=='E' || c=='e' || c == 'I' || c== 'i' || c=='o' || c == 'O' || c=='u' || c== 'U'){
            atleatonevowel = true;
            std::cout<<c<<"\n";
        }
    }
    if(!atleatonevowel){
        std::cerr<<"No vowel found\n";
    }
}


int main(){
    datacontainer data1{"", "abc", "xyz", "vivi"};
    datacontainer data2{"", "", "", ""};
    datacontainer data3 {};
    try{
        // Adaptor(&findVowels, data1);
        // Adaptor(&findVowels, data2);
        Adaptor(&findVowels, data3);
    }
    catch(std::invalid_argument& ex){
        std::cerr<<ex.what()<<"\n";
    }
    Adaptor( [](const std::string& st) {std::cout<<st.length();} , data1);//users can add the extra logic from their side using this 
}