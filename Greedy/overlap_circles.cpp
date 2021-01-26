#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{

    int n;
    cin >> n;
    vector<pair<int, int>> p;
    int x,y;
    for (int i = 0; i < n; i++)
    {
        cin>>x>>y;
        p.push_back(make_pair(x,y));
    }

    for (int i = 0; i < n; i++)
    {
        int c = p[i].first;
        int r = p[i].second;
        p[i].first = c-r;
        p[i].second = c+r;
    }
    // for(int i=0;i<n;i++){
    //     cout<<p[i].first<<" "<<p[i].second<<endl;
    // }
    sort(p.begin(),p.end(), compare);

    int ans = 0;
    int current = p[0].second;
    for (int i = 1; i < n;i++)
    {
        if (p[i].first > current)
        {
            current = p[i].second;
        }
        else{
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}