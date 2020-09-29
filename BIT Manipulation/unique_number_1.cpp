#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n;i++)
    {
        cin >> ar[i];
    }
    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        ans ^= ar[i]; // xor operator
    }
    cout << ans;
}