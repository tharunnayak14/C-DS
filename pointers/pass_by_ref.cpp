#include<iostream>
using namespace std;
/*
void increment_by_value(int a){
    a++;
    cout << a << "\n";// prints 11
}
*/
void increment_by_ref(int * a){
    *a = *a + 1;
    cout <<"inside increment_by_ref "<< *a << "\n";
}
int main(){
    int a = 10;
    //increment_by_value(a);
    //cout <<"increment by value "<< a;// prints 10
    increment_by_ref(&a);
    cout << "increment by ref " << a;
}