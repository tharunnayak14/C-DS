#include<iostream>
using namespace std;
void prime_sieve(int p[], int n) {
    for ( int i = 3; i <= 1000000;i+=2)
    {
        p[i] = 1;
    }
    for ( int i = 3; i <= 1000000;i+=2)
    {
        // if current num is not marked(it is prime)
        if(p[i]==1)
        {
            // mark all its multiples as not prime
            for ( int j = i * i; j <= 1000000;j+=i)
            {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
	int count=0;
    for ( int i = 0; i <= 1000000;i++)
    {
        if(p[i]==1)
        {
            count++;
			if(count==n)
				cout<<i;
			break;
        }
    }
}
int main() {
	int n;
    cin >> n;
	int p[1000000] = {0};
    prime_sieve(p, n);
	return 0;
}