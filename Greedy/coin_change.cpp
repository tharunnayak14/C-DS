#include <bits/stdc++.h>
using namespace std;

int make_change(int *coins, int money, int t)
{
    // we need a number > 39 idx(50)-1 = idx(20)
    int ans = 0;
    while (money > 0)
    {

        int index = upper_bound(coins, coins + t, money) - 1 - coins;
        cout << coins[index] << " ";
        money = money - coins[index];
        ans++;
    }
    cout<<endl;
    return ans;
}
int main()
{
    int n;
    cin >> n;

    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int t = sizeof(coins) / sizeof(int);

    cout<<make_change(coins, n, t);
    return 0;
}
