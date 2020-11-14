#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a, string b){
    if(a.length()==b.length())
        return a < b;
    return a.length() < b.length();
}

int main(){
    string s[100];
    int n, i=0;
    cin >> n;
    cin.get();
    for (int i = 0; i < n;i++){
        getline(cin, s[i]);
    }

    sort(s, s + n, compare);// lexographically

    // to sort length wise use comperator
    cout << "sorted strings"
         << "\n";
    for (int i = 0; i < n;i++){
        cout << s[i]<<"\n";
    }

    return 0;
}