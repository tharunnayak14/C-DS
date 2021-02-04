#include<bits/stdc++.h>
using namespace std;
int jumps(int n, int k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    // if(n==2){
    //     return 2;
    // }
    // if(n==3){
    //     return 4;
    // }
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans+=jumps(n-i,k);
    }

    return ans;
}
int main(){

    int n;
    cin>>n;
    int k;
    cin>>k;

    cout<<jumps(n, k);
    return 0;
}