void demo(int n1){
    /*
        n1 is a non const int by value
        lvalue will be copied, rvalues are assigned. bothare accepted
        n1 shall not remain const in demo function (so can be modified)
    */
}
void demo(int& n1)
{
    /*
        n1 is a non const regerence to an integer
        lvalues can be accepted as a reference(no copy, no address received)
        n1 can be modified but it will modity original data passed

        example : int n1{10};int demo(n1);
    */
    
}


void demo(const int n1)
{
    
 /*
        n1 is a non const int by value
        lvalue will be copied, rvalues are assigned. bothare accepted
        n1  remain const in demo function (so can't be modified)
    */
}


void demo(const int& n1){
    /*
        n1 is a const lvalue reference to an integer
        lvalues and rvalues are both accepted

        lvalues will be referred, rvalues will be to assigned to n1 either way, n1 cannot be modified inside demo funtion
    */
    
}

void demo(int&& n1){
    /*
        n1 is non const rvalue regerence to an integer only rvalues are accepted, rvalues will be assigned to n1
        n1 can be modified
    */

}

void demo(const int&& n1){
    /*
        n1 is a constant rvalue reference to an int ,only rvalues are accepted, rvalues will be assigned to n1
        n1 cannot be modified in demo
    */
}


void demo(int* n1){
    /*
    n1 is a pointer to an integer
    an rvalue or lvalue address must be provided here
    n1 can change pointer it is holding. n1 can also modify data at the given location
    main:
    int value{10};
    demo(&value);
 
    demo
    -----
    int* n1=&value;
 
*/
}

void demo(const int* n1){
    /*
         n1 is a pointer to a  const integer
         n1 can change the location it points to but data tat the location shall remain non modified
    */
}

void demo(int* const n1)
{
    /*
         n1 is a constant pointer to a non const int
         n1 can modify the data at the location is holds. but n1 cannot reassigned to a diffferent memory location
    */
}



void demo(const int* const n1){
    // n1 is constant pointer to a contant int
    // n1 cannot be reassigned. data cannot be modified ysing n1 either

}