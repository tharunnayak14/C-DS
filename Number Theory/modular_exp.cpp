#include<iostream>
using namespace std;
long long int fast(int x, int n, int y){
	x = x%y;
	long long int ans = 1;
	if(x==0)
		return 0;
	while(n>0){
		if(n&1){
			ans=  (ans*x)%y;
		}
		n=n>>1;
		x = (x*x)%y;
	}
	return ans;
}

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	cout<<fast(a,b,c);
	return 0;
}

// (a+b)%m = ((a%m)+(b%m))%m;
// (a-b)%m = ((a%m)-(b%m)+m)%m;
// (a*b)%m = ((a%m)*(b%m))%m;
// (a/b)%m = ((a%m)*(b(inverse)%m))%m;

// pow(a,b)%m = pow(a%m, b)%m;