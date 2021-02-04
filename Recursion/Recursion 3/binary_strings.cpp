#include<bits/stdc++.h>
using namespace std;
int count(int n){
    if(n==1){
        return 2;
    }
    if(n==2){
        return 3;
    }
    return count(n-1)+count(n-2);
}

int main(){

    int n;
    cin >> n;
    cout<<count(n);
}