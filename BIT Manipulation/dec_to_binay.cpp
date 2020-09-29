#include<iostream>

using namespace std;
int binary(int n) {
    int ans = 0;
    int p = 1;
    while(n>0)
    {
        ans += p * (n & 1);
        n = n >> 1;
        p *= 10;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    cout<<binary(n);
    return 0;
}