#include<iostream>
using namespace std;
int clear_range_i_to_j(int n, int i, int j) {
    int a = -1 << (j + 1);
    int b = (1 << i) - 1;
    return n & (a | b);
}
int replace(int n, int m, int i, int j) {
    /*
        let n = 1011011111
        let m = 1101
        i = 1
        j = 4
        clear all bits from range i to j gives
        n = 1011000001
        m = m<<i;
        makes m = 11010

        now simply take or of both n and m which gives

        10110(1101)1 replaced
    */
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
