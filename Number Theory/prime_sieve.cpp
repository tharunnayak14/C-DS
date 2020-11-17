#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

void prime_sieve(ll *p){
    //mark all odd primes
    for(ll i=3;i<=1000000;i+=2){
        p[i] = 1;
    }

    // complexity n/2 + n/3 + ..... + n/97 +.....
    // O(nlog(log n)) //approx linear
    for(ll i=3;i<=1000000;i+=2){

        //if current num is not marked (it is prime)
        if(p[i]==1){
            //mark all the multiples as not prime
            //initialise j with i*i using condition that 
            // for any n 1 divisor of n is possible which is <=sqrt(n)
            for(ll j = i*i;j<=1000000;j+=i){
                p[j] = 0;
            }
        }
    }
    //special cases
    p[0]=0;
    p[1]=0;
    p[2]=1;

}
int main(){

    ll n;
    cin>>n;
    ll p[1000000]={0};
    prime_sieve(p);
    
    vector<ll> v;
    v.reserve(1000000);
    //primes less than or equal to n
    for(ll i=0;i<n;i++){
        if(p[i]==1){
            cout<<i<<" ";
            v.push_back(i);
        }
    }
    cout<<"\n";
    //print first 5 primes
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}