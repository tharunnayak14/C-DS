#include<iostream>
using namespace std;
int slow_method(int n) {
    // complexity O(no of bits)

    // atmax there are log(n)+1 bits for a number n
    int ans = 0;
    while(n>0)
    {
        ans += n & 1 ? 1 : 0;
        n = n >> 1;
    }
    return ans;
}
int efficient_method(int n) {
    // complexity O(no of set bits)
    int ans = 0;
    //no of times while loop runs is ans
    while(n>0)
    {
        n = n & (n - 1); // this line removes the last set bit (goes from right to left)
        // let n   = 1001
        // n-1     = 1000
        // n&(n-1) = 1000
        ans++;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    cout << slow_method(n)<<"\n";
    cout << efficient_method(n) << "\n";
    cout << __builtin_popcount(n) << "\n"; // inbuilt function in cpp to find no of set bits
    return 0;
}
