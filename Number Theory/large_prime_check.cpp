#include<iostream>
#include<bitset>
#include<vector>

using namespace std;

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void sieve(){
    b.set();
    b[0] = b[1] = 0;

    for(long long int i=2;i<=n;i++){
        if(b[i]){
            primes.push_back(i);
            for(long long int j = i*i;j<=n;j+=i){
                b[j] = 0;
            }
        }
    }
}
bool isprime(long long num){
    if(num<=n){
        return b[num]==1?true:false;
    }
    for(int i=0;primes[i]*(long long)primes[i]<=num;i++){
        if(num%primes[i]==0){
            return false;
        }
    }
    return true;
}

int main(){
    sieve();

    if(isprime(2147483647)){
        cout<<"yes baby"<<endl;
    }
    else{
        cout<<"oh noo   oh noo"<<endl;
    }
    return 0;
}