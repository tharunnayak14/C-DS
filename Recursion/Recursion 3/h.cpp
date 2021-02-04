#include <bits/stdc++.h>
using namespace std;
void replace_pi(string s, int i)
{
    // base case
    if (s[i] == '\0' or s[i + 1] == '\0')
    {
        return;
    }
    // look for pi at current loc
    if (s[i] == 'x')
    {
        string v = s.substr(0, i);
        string u = s.substr(i + 1, s.length() - i - 1);
        // cout<<v<<" "<<u<<endl;
        s = v + u;
        string y = "x";
        s.append(y);
       // cout<<s<<endl;
        replace_pi(s, i+1);
    }
    else
    {
        // go to the next pos
        replace_pi(s, i + 1);
    }
    cout<<s<<endl;
}
int main()
{

    string s;
    getline(cin,s);
    //cout << s << endl;
    replace_pi(s, 0);
    //cout << s << endl;
}