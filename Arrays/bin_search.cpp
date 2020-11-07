#include<iostream>
using namespace std;


int bin_search(int ar[], int n, int key){
    int s = 0;
    int e = n - 1;
    while(s<=e){
        int mid = (s + e) / 2;
        if(ar[mid]==key){
            return mid;
        }
        else if(ar[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return -1;
}
int main() {

    int n, key;
    cin >> n;
    // initialising array
    int ar[1000];
    // taking input
    for (int i = 0; i < n;i++){
         cin >> ar[i];
    }
    cout << "Enter element to be searched:";
    cin >> key;
    cout << "Found at index:" <<bin_search(ar, n, key);
    return 0;
}