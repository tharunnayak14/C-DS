#include<iostream>
using namespace std;

int main() {

    int n, key;
    cin >> n >> key;
    // initialising array
    int ar[1000];
    // taking input
    for (int i = 0; i < n;i++){
         cin >> ar[i];
    }
    //iterating for key
    int i;
    for (i = 0; i < n;i++){
        if(ar[i]==key)
        {
            cout << "found at index " << i << "\n";
            break;
        }
    }
    // if key not found, i becomes equal to n
    if(i==n)
    {
        cout << "Not found"
             << "\n";
    }
        return 0;
}