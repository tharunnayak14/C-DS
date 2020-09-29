#include<iostream>

using namespace std;
int main() {
    int n,num;
    cin >> n;
    int c[64] = {0}; // array for storing sum of all bits
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        int j = 0;
        //update count array by extracting bits
        while(num>0)
        {
            c[j] += (num & 1);//last bit
            j++;
            num = num >> 1;
        }
    }
    int ans = 0;
    int p = 1;
    // iterate over array and reduce everyting by %3
    // as sum is of form 3n or 3n+1;
    for (int i = 0; i < 65;i++)
    {
        c[i] %= 3;
        ans += (c[i] * p); // convert back to decimal
        p = p << 1;
    }
    cout << ans << "\n";
    return 0;
}
