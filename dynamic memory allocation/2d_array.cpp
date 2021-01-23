#include<iostream>
using namespace std;
int main(){
    int **arr;
    int r, c;
    int val = 1;
    cin >> r >> c;
    arr = new int *[r];
    for (int i = 0; i < r;i++){
        arr[i] = new int[c];
    }

    // input and print
    for (int i = 0; i < r;i++){
        for (int j = 0; j < c;j++){
            arr[i][j] = val;
            val++;
            cout << arr[i][j];
        }
        cout << "\n";
    }
    for (int i = 0; i < r;i++){
        delete[] arr[i];
    }
    delete arr;
}