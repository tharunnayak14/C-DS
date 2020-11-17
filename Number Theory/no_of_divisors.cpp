#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> prime_sieve(ll *p, ll n){
    //mark all odd primes
    for(ll i=3;i<=n;i+=2){
        p[i] = 1;
    }

    // complexity n/2 + n/3 + ..... + n/97 +.....
    // O(nlog(log n)) //approx linear
    for(ll i=3;i<=n;i+=2){

        //if current num is not marked (it is prime)
        if(p[i]==1){
            //mark all the multiples as not prime
            //initialise j with i*i using condition that 
            // for any n 1 divisor of n is possible which is <=sqrt(n)
            for(ll j = i*i;j<=n;j+=i){
                p[j] = 0;
            }
        }
    }
    //special cases
    p[0]=0;
    p[1]=0;
    p[2]=1;
    vector<ll> primes;
    primes.push_back(2);
    for(ll i=3;i<=n;i++){
        if(p[i]==1)
            primes.push_back(i);
    }

    return primes;

}
int no_of_divisors(int m, vector<ll>&primes){

    ll i=0;
    ll p = primes[0];
    int ans = 1;
    while(p*p<=m){

        if(m%p==0){
            int count = 0;
            while(m%p==0){
                count++;
                m/=p;
            }
            ans*= (count+1);
        }
        i++;
        p = primes[i];
    }

    if(m!=1){
        ans*=2;
    }


    return ans;
}
int main() {
    ll n = 1000000;
    ll p[n] = {0};
    vector<ll>primes = prime_sieve(p, 100);

    int t;
    cin>>t;
    while (t--)
    {
        int num;
        cin>>num;

        int divisors = no_of_divisors(num, primes);
        cout<<divisors<<endl;
    }
    

    return 0;
}