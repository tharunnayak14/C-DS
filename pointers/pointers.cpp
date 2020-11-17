#include<iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    cout << &x<<"\n";
    char ch = 'a';
    cout << &ch << "\n";// prints a
    // typecasting from char * to void *
    cout << (void *)&ch << "\n";// prints address of a

    // pointer
    int *ptr = &x;
    cout <<"ptr " <<ptr<<" or "<< " &x "<<&x<<" are same" << "\n";

    // dereferance operator

    int a = 10;
    int *aptr = &a;

    cout << &a << "\n";
    cout << aptr<<"\n";
    cout << *aptr << "\n";
    cout << *(&aptr) << "\n";
    cout << &(*aptr) << "\n";
    cout << *aptr + 1<<"\n";
    cout << *(aptr + 1)<<"\n";

    // double pointer
    cout << "double pointer"
         << "\n";
    int b = 3;
    int *bptr = &b;
    int **bbptr = &bptr;
    cout << b << "\n";
    cout << bptr << "\n";
    cout << *bptr << "\n";
    cout << bbptr << "\n";
    cout << *bbptr << "\n";
    cout << **bbptr << "\n";
    return 0;
}