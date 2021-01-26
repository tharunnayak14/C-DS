#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, t;
        cin >> a >> b >> t;
        int ar1[t], ar2[t];
        for (int i = 0; i < t; i++)
        {
            cin >> ar1[i] >> ar2[i];
        }
        sort(ar1, ar1 + t);
        sort(ar2, ar2 + t);

        int diff1=ar1[0]-1;
        int diff2=ar2[0]-1;
        //cout << diff1 << " " << diff2 << endl;
        for (int i = 1; i < t; i++)
        {
            diff1 = max(diff1, ar1[i] - ar1[i - 1] - 1);
            diff2 = max(diff2, ar2[i] - ar2[i - 1] - 1);
            //cout << diff1 << " " << diff2 << endl;
        }
        diff1 = max(diff1, a - ar1[t - 1]);
        diff2 = max(diff2, b - ar2[t - 1]);
        //cout << diff1 << " " << diff2 << endl;
        cout << diff2 * diff1 << endl;
    }

    return 0;
}