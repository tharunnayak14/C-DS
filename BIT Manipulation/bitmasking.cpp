#include<iostream>
using namespace std;
bool is_odd(int n) {
    // last bit = n&1
    return (n&1);
}
int get_bit(int n, int i) {
    //n =    00101
    //mask = 00100 (1<<i)
    //n&mask= 00100 > 0 means set bit , ==0 means zero
    return (n & (1 << i)) > 0 ? 1 : 0;
}
int set_bit(int n, int i) {
    // n   =  00001
    //mask =  00100 (1<<i)
    //n or mask = 00101 makes the ith bit set
    n = (n | (1 << i));
    return n;
}
int clear_bit(int n, int i) {
    // mask = ~(1<<i) flips all bits ex 111011 for i=2;
    // n&(~(1<<i)) this makes the ith bit 0, if bit is 1 we take and with 1 so no change and if bit is 0 and     with 1 its 0 but the ith bit has 0 so and always clears the bit
    n = n & (~(1 << i));
    return n;
}
int update_bit(int n, int i, int v) {
    n = n & (~(1 << i));//clear the ith bit
    int mask = v << i;  //mask;
    return n | mask;
}
int clear_last_i_bits(int n, int i) {
    int mask = -1 << i; // ex 11111110000
    return n & mask;    // clears all the last i bits
}
int clear_range_i_to_j(int n, int i, int j) {
    // mask should be of form 1111100000111111
    int a = -1 << (j + 1); // 1111100000000000
    int b = (1 << i) - 1;  // 0000000000111111
    // a or b  gives the required mask
    return n & (a | b);
}
int main() {
    int n = 31;
    int i;
    cin >> i;
    if(is_odd)
    {
        cout << "odd\n";
    }
    else
    {
        cout << "even\n";
    }
    // cout << get_bit(n, i)<<"\n";
    // cout << set_bit(n, i)<<"\n";
    // cout << clear_bit(n, i) << "\n";
    // cout << update_bit(n, i, 1) << "\n";
    // cout << clear_last_i_bits(n, i)<< "\n";
    // cout << clear_range_i_to_j(n, 1, 3);
    return 0;
}