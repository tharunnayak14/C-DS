#include<bits/stdc++.h>
using namespace std;
int profit(int n,int c,int *w, int * p){
    if(n==0 or c==0){
        return 0;
    }
    int ans =0;
    int inc,exc;
    inc = exc  = INT_MIN;
    if(w[n-1]<=c)
    inc= p[n-1]+profit(n-1,c-w[n-1],w,p);
    exc = profit(n-1,c,w,p);

    ans= max(inc,exc);
    return ans;
}
int main(){

    int max_weight;
    cin>>max_weight;

    int n;
    cin>>n;
     
    int weight[n];
    int prices[n];

    for(int i=0;i<n;i++){
        cin>>weight[i];
        cin>>prices[i];
    }

    cout<<profit(n,max_weight,weight,prices);

    

    
    return 0;
}