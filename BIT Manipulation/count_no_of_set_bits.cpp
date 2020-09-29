#include<iostream>
using namespace std;
int count_set_bits(int n) {
    int ans = 0;
    while(n>0)
    {
        ans += n & 1 ? 1 : 0;
        n = n >> 1;
    }
    return ans;
}
int second_method(int n) {
    int ans = 0;
    while(n>0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    cout<<count_set_bits(n)<<"\n";
    cout << second_method(n) << "\n";
    cout << __builtin_popcount(n) << "\n";
    return 0;
}