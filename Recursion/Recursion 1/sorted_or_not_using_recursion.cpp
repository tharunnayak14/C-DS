#include<iostream>
using namespace std;
bool is_sorted(int ar[], int n){
    if(n==0||n==1){
        return true;
    }
    if(ar[0]<ar[1] and is_sorted(ar+1, n-1)){
        return true;
    }
    return false;
}
int main(){
    int ar[] = {1, 2, 3, 4, 5};    int n = sizeof(ar) / sizeof(int);
    cout<<is_sorted(ar, n);
    return 0;
}
