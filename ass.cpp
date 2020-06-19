#include <bits/stdc++.h>
using namespace std;
int fun(int ar[],int n,int x){
	int i;
	for ( i = 0; i < n && ar[i] != x; ++i)
	{
		if(i == n)
			return -1;
		else 
			return i;
	}
}
int main(){

	#ifndef ONLINE_JUDGE // taking input from local files and printing output to other files
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif
	int n;
	cin >> n;
	int x;
	cin >> x;
	int ar[] = {1,2,3,4};
	cout << fun(ar,n,x);

}