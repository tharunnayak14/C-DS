#include<iostream>
#include<string>
using namespace std;
void filter(string s, int n) {
    int j = 0;
    while(n>0)
    {
        if(n&1)
        {
            cout << s[j];
        }
        j++;
        n = n >> 1;
    }
    cout << "\n";
}
void print_subsets(string a) {
    int n = strlen(a);
    for (int i = 0; i < (1<<n);i++)
    {
        cout<<filter(a, i)<<"\n";
    }
}
int main() {
    int n;
    cin >> n;
    string s = "abc";

    return 0;
}