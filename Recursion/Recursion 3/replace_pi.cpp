#include <bits/stdc++.h>
using namespace std;
void replace_pi(char s[], int i)
{
    // base case
    if (s[i] == '\0' or s[i+1]=='\0')
    {
        return;
    }
    // look for pi at current loc
    if (s[i] == 'p' and s[i + 1] == 'i')
    {
        // shifting
        int j = i + 2;
        //take j to the end of array
        while (s[j] != '\0')
        {
            j++;
        }
        while (j >= i + 2)
        {
            s[j + 2] = s[j];
            j--;
        }
        //replacing 3.14
        s[i] = '3';
        s[i + 1] = '.';
        s[i + 2] = '1';
        s[i + 3] = '4';

        replace_pi(s, i + 4);
    }
    else
    {
        // go to the next pos
        replace_pi(s, i + 1);
    }
}
int main()
{
    char s[1000];
    cin >> s;
    cout << s<<endl;
    replace_pi(s, 0);
    cout << s << endl;
}