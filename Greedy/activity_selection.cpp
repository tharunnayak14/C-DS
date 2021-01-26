#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        pair<int, int> p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first;
            cin >> p[i].second;
        }
        sort(p, p + n, compare);

        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if(p[i].first >= p[i-1].second){
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}