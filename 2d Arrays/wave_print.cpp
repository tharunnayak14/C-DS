#include<iostream>
using namespace std;

int main(){
    int n, val=1;
    cin >> n;
    int ar[n][n];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            ar[i][j] = val++;
            cout<< ar[i][j]<<" ";
        }
        cout << "\n";
    }

    //Wave print
    
    cout << "Wave print"
         << "\n";
    for (int col = 0; col < n;col++){
        if(col%2==0){
            for (int row = 0; row < n;row++){
                cout << ar[row][col] << " ";
            }
        }
        else{
            for (int row = n - 1; row >= 0;row--){
                cout << ar[row][col] << " ";
            }
        }
    }
    return 0;
}