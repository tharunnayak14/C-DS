#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll n,d;
    cin>>n>>d;
    ll ar[n];
    for(ll i=0;i<n;i++){
        cin>>ar[i];
    }
    int ans=0;
    sort(ar,ar+n);
    for(ll i=0;i<n-1;){
        if(ar[i+1]-ar[i]<=d){
            i+=2;
            ans++;
        }
        else{
            i++;
        }
    }
    cout<<ans<<endl;

    return 0;
}