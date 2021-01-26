#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int arr[100];
    ll n, val, i, diff;
    //Take input Current Test Case
    ll max_load = 0, load = 0;
    cin >> n;
    //Stop taking input if n=-1;
    if (n == -1)
    {
        break;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        load = load + arr[i];
    }
    if (load % n != 0)
    {
        cout << -1 << endl;
        continue;
    }
    //Find the load that is to be divided equally
    load = load / n;

    diff = 0;
    //greedy step
    for (int i = 0; i < n; i++)
    {
        //find the differeence between final load to be assigned and calculated
        diff += (arr[i] - load);
        ll ans = max(diff, -diff);
        max_load = max(max_load, ans);
    }
    cout << max_load << endl;

    return 0;
}