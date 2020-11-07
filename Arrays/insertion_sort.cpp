#include<iostream>
using namespace std;

void insertion_sort(int ar[],int n){
    for (int i=0; i <n; i++){
        int e = ar[i];
        int j = i-1;
        while(j>=0 and ar[j]>e){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = e;
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n;i++){
        cin >> ar[i];
    }
    insertion_sort(ar, n);
    for (int i = 0; i < n;i++){
        cout << ar[i] <<" ";
    } 
    return 0;

}