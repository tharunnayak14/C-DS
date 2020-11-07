#include<iostream>
#include<climits>
using namespace std;

int main() {

    int n;
    cin >> n;
    // initialising array
    int ar[1000];
    // taking input
    for (int i = 0; i < n;i++){
         cin >> ar[i];
    }
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n;i++){
        if(ar[i]>=max){
            max = ar[i];
        }
        if(ar[i]<=min){
            min = ar[i];
        }
    }
    cout << max << "\n";
    cout << min << "\n";
    return 0;
}