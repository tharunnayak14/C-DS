#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v1,v2;
        v1.reserve(n);
        v2.reserve(n);
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            v1.push_back(x);
        }
        for(int i=0;i<n;i++){
            cin>>x;
            v2.push_back(x);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(v1[i]-v2[i]);
        }
        cout<<ans<<endl;
    }
    
}