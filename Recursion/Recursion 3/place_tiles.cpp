#include<bits/stdc++.h>
using namespace std;
int place_tiles(int n){
    if(n<=3){
        return 1;
    }
    return place_tiles(n-1)+place_tiles(n-4);
}
int main()
{
    int n;
    cin>>n;

    cout<<place_tiles(n);
}