#include<iostream>
using namespace std;
long long int power(long long int a, long long int n){
    if(n==1){
        return a;
    }
    else{
        return a * power(a, n - 1);
    }
}
long long int fast_power(long long int a, long long int n){
    if(n==1){
        return a;
    }
    if(n==0){
        return 1;
    }
    int small = fast_power(a, n / 2);
    small *= small;
    if(n&1){
        return a * small;
    }
    return small;
}
int main(){
    long long int a, n;
    cin >> a >> n;
    cout<<power(a, n)<<"\n";
    cout << fast_power(a, n);

    return 0;
}