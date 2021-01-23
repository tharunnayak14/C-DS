#include<iostream>
using namespace std;

int main() {

    // allocate + deallocate by compiler
    int b[100] = {1};
    cout << "size of b is " << sizeof(b)<<"\n"; // 4*100 = 400
    cout << b << "\n"; // taken from symbol table can't be overwritten
    // b is a constant

    // dynamic memory allocation

    int n;
    cin>>n;
    // allocating memory
    int * a = new int [n];// rem this a is a pointer to the array
    // int * a = new int [n]{0}; initialising with zero
    cout << "size of a is " << sizeof(a) << "\n"; // only 4 as its a pointer
    cout << a << "\n"; // a is a pointer which points to 1st element of array
    // as it is a pointer can be reallocated/overwritten

    // a = new char[10];

    for (int i = 0; i < n;i++){
        cin >> *(a+i);
        cout << a[i] << " ";
        // or use cout << *(a+i)
    }
    // free up the space
    delete[] a;

    return 0;
}