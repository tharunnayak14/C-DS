#include<iostream>
using namespace std;
int clear_range_i_to_j(int n, int i, int j) {
    int a = -1 << (j + 1);
    int b = (1 << i) - 1;
    return n & (a | b);
}
int replace(int n, int m, int i, int j) {
    int x = clear_range_i_to_j(n, i, j);
    return x | (m<<i);
}
int main() {
    int n = 15;
    int i = 1;
    int j = 3;
    int m = 2;
    cout<<replace(n, m, i, j);
    return 0;
}