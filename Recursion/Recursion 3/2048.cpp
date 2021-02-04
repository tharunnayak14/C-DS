#include<bits/stdc++.h>
using namespace std;
void print_spell(int n){
    char a[][10]= {"zero", "one", "two","three","four","five","six","seven","eight","nine"};
    if(n==0){
        return;
    }
    print_spell(n/10);
    cout<<a[n%10]<<" ";
    return;
}
void print_spell_rev(int n){
    char a[][10]= {"zero", "one", "two","three","four","five","six","seven","eight","nine"};
    if(n==0){
        return;
    }
    cout<<a[n%10]<<" ";
    print_spell_rev(n/10);
    return;
}
int main(){
    int n;
    cin>>n;

    print_spell(n);
    cout<<endl;
    print_spell_rev(n);
    return 0;
}