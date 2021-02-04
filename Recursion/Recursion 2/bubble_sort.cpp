#include<bits/stdc++.h>
using namespace std;
void bubble(int *a, int n, int j){
    if(n==1){
        return;
    }
    if(j==n-1){
        return bubble(a,n-1,0);
    }
    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
    bubble(a,n,j+1);
}
int main(){
    int a[] = {1,2,2,3,3,3,4,5,46,23,12};
    int n  = sizeof(a)/sizeof(int);
    bubble(a,n,0);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}