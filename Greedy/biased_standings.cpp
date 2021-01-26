#include<bits/stdc++.h>
using namespace std;
bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        pair<string,int> p[n];
        for(int i=0;i<n;i++){
            cin>>p[i].first;
            cin>>p[i].second;
        }
        sort(p,p+n,compare);
        // for(int i=0;i<n;i++){
        //     cout<<p[i].first<<" "<<p[i].second<<endl;
        // }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += (abs(i+1-p[i].second));
        }
        cout<<ans<<endl;
    }
}