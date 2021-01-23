#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class strings
{
    
public:
    string s1, s2;

    int make_same(string &s1, string &s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 < len2)
        {
            for (int i = 0; i < len2 - len1; i++)
                s1 = '0' + s1;
            return len2;
        }
        else if (len1 > len2)
        {
            for (int i = 0; i < len1 - len2; i++)
                s2 = '0' + s2;
        }
        return len1;
    }
    string add_Strings(string s1, string s2)
    {
        string result;

        // make the lengths same before adding
        int length = make_same(s1, s2);
        int carry = 0;

        for (int i = length - 1; i >= 0; i--)
        {
            int firstBit = s1[i] - '0';
            int secondBit = s2[i]- '0';

            // boolean expression for sum of 3 bits
            int sum = (firstBit ^ secondBit ^ carry) + '0';

            result = (char)sum + result;

            // boolean expression for 3-bit addition
            carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
        }

        // if overflow, then add a leading 1
        if (carry)
            result = '1' + result;

        return result;
    }

    int multiply_1bit(string s1, string s2)
    {
        return (s1[0] - '0') * (s2[0] - '0');
    }

    // The main function that multiplies two bit strings X and Y and returns
    // result as long integer
    ll multiply(string X, string Y)
    {
        // Find the maximum of lengths of x and Y and make length
        // of smaller string same as that of larger string
        int n = make_same(X, Y);

        // Base cases
        if (n == 0)
            return 0;
        if (n == 1)
            return multiply_1bit(X, Y);

        int l = n / 2;
        int r = (n - l);

        string Xl = X.substr(0, l);
        string Xr = X.substr(l, r);

        string Yl = Y.substr(0, l);
        string Yr = Y.substr(l, r);

        // Recursively calculate the three products of inputs of size n/2
        ll a = multiply(Xl, Yl);
        ll b = multiply(Xr, Yr);
        ll c = multiply(add_Strings(Xl, Xr), add_Strings(Yl, Yr));

        return a * (1 << (2 * r)) + (c - a - b) * (1 << r) + b;
    }
};

int main()
{
    strings s;
    getline(cin, s.s1);
    getline(cin, s.s2);

    cout << s.multiply(s.s1, s.s2);
}
