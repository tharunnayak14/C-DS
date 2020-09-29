#include<iostream>

using namespace std;

int main() {
    int n,num;
    cin >> n;
    int c[64] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        int j = 0;
        while(num>0)
        {
            c[j] += (num & 1);
            j++;
            num = num >> 1;
        }
    }
    int ans = 0;
    int p = 1;
    for (int i = 0; i < 65;i++)
    {
        c[i] %= 3;
        ans += (c[i] * p);
        p = p << 1;
    }
    cout << ans << "\n";
    return 0;
}