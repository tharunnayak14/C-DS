#include<iostream>
using namespace std;

int main(){
    int ar[3][3]={0};
    int val = 1;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            ar[i][j] = ++val;
            cout<< ar[i][j]<<" ";
        }
        cout << "\n";
    }
    return 0;
}