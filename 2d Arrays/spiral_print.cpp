#include<iostream>
using namespace std;

void spiral(int ar[][100], int n){
    int sr = 0;
    int sc = 0;
    int er = n - 1;
    int ec = n - 1;

    while (sr<=er and sc<=ec){
        for (int i = sc; i <= ec;i++){
            cout << ar[sr][i]<<" ";
        }
        sr++;
        for (int i = sr; i <= er;i++){
            cout << ar[i][ec]<<" ";
        }
        ec--;
        if(er > sr){
        for (int i = ec; i >= sc;i--){
            cout << ar[er][i] << " ";
        }
        er--;
        }
        if(ec>sc){
        for (int i = er; i >= sr;i--){
            cout << ar[i][sc] << " ";
        }
        sc++;
        }
    }
    
}

int main(){
    int n, val=1;
    cin >> n;
    int ar[100][100];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            ar[i][j] = val++;
            cout<< ar[i][j]<<" ";
        }
        cout << "\n";
    }

    //Spiral print
    spiral(ar, n);
    return 0;
}