#include<iostream>
using namespace std;

//gcd(a,b) = gcd(b, a%b);
//gcd(a,0) = a;

int gcd(int n, int t){

    return t==0? n: gcd(t,n%t);
}

// lcm * gcd = a * b
int lcm(int n, int t){
    return (n * t) / gcd(n, t);
}
int main(){
    int n,t;
    cin>>n>>t;
    cout<<gcd(n, t)<<"\n";
    cout << lcm(n, t) << "\n";
}