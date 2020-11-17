#include<bits/stdc++.h>
#define ll long long
ll ar[1000005], pre[1000005];
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(pre, 0, sizeof(pre));

        pre[0] = 1;
        ll sum = 0;
        for (int i = 0; i < n;i++){
            cin >> ar[i];
            sum += ar[i];
            sum = (sum + n) % n;
            pre[sum]++;
        }
        ll ans = 0;
        for (int i = 0; i < n;i++){
            ll m = pre[i];
            ans += m * (m - 1) / 2;
        }
        cout << ans << "\n";
    }
    
}