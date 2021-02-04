#include<iostream>
using namespace std;
void dec(int n){
    if(n==1){
        cout << 1;
        exit(0);
    }
    else{
        cout << n;
    }
    dec(n-1);
}
void inc(int n){
    if(n==0)
        return;
    inc(n - 1);
    cout << n;
}
int main(){
    int n;
    cin >> n;

    //dec(n);
    cout << "\n";
    inc(n);
    return 0;
}