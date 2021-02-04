#include<bits/stdc++.h>
using namespace std;
void tower_of_hanoi(int n, char src, char aux, char dest){
    if(n==0){
        return;
    }
    // rec case
    // shift n-1 from src to aux using dest as helper
    tower_of_hanoi(n-1,src,dest,aux);
    cout<<"shift disk "<<n<< " from "<<src<<" to "<<dest<<endl;
    // shift these from aux to dest using src as helper
    tower_of_hanoi(n-1, aux, src, dest);
}
int main(){
    int n;
    cin>>n;

    tower_of_hanoi(n,'A','B','C');


    return 0;
}