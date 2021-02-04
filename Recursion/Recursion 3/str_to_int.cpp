#include <bits/stdc++.h>
using namespace std;
int str_to_int(string s, int l)
{
    if (l == 0)
    {
        return 0;
    }
    int digit = s[l - 1] - '0';
    int small = str_to_int(s, l - 1);

    return small * 10 + digit;
}
int main()
{

    string s = "312312";
    int l = s.length();

    int x = str_to_int(s, l);
    cout << x << " " << x + 1 << endl;
    int y = str_to_int_reverse(s,l);
    cout<<y<<" "<<y+1<<endl;
}