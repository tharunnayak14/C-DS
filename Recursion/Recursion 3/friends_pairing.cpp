#include<bits/stdc++.h>
using namespace std;
int ways(int n, int bikes){

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return ways(n-1,n-1) + (n-1)*ways(n-2,n-2);

}
int main()
{
    int n;
    cin>>n;
    int bikes;
    bikes = n;

    cout<<ways(n, bikes);
}