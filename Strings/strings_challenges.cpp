#include<bits/stdc++.h>
using namespace std;
void UPPER(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' and s[i]<='z'){
            s[i]-=32;
        }
    }
    cout<<s<<endl;
}
void lower(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' and s[i]<='Z'){
            s[i]+=32;
        }
    }
    cout<<s<<endl; 
}
int main(){
    string s;
    getline(cin, s);
    cout<<s<<endl;
    UPPER(s);
    lower(s);

    transform(s.begin(), s.end(), s.begin(), ::toupper); // easy way
    cout<<s<<endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);// takes 4 arguments begin, end,from where to capitailse, to which case
    cout<<s<<endl;
    
    //largest numeric number from given string
    // ex "12345" ans 54321

    string s2 = "3278942";

    sort(s2.begin(), s2.end()); //smalles number
    cout<<s2<<endl;
    sort(s2.begin(), s2.end(), greater<int>());// largest number , passing comperator
    cout<<s2<<endl;

    // char with max freq

    string s3 = "tharunnayak";
    vector<int> ar(26,0);
    for(int i=0;i<s3.length();i++){
        ar[s3[i]-'a']++;
    }
    cout<<*max_element(ar.begin(), ar.end());


}
