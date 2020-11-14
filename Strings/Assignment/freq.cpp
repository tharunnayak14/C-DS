#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void compress(string s){
	int count=0;
	for(int i=0;i<s.length();i++){
		count = 0;
		for(int j=0;j<s.length();j++){
			if(s[i]==s[j])
				count++;			
		}
        cout<<s[i]<<count;
        i += count-1;
    }
}
string remove_dup(string str){
    sort(str.begin(), str.end()); 
  
    // Using unique() method 
    auto res = unique(str.begin(), str.end());

	return string(str.begin(), res);
} 
int main() {
	string s;
	getline(cin, s);
	int n = sizeof(s) / sizeof(s[0]);
	cout<<remove_dup(s)<<"\n";
	compress(remove_dup(s));
	return 0;
}