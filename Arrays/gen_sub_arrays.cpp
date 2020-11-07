#include<iostream>
using namespace std;

void gen_subarray(int ar[], int n){
    for (int i = 0; i < n;i++){

        for (int j = i; j < n;j++){

            // print elements of current sub array(i, j)
            for (int k = i; k <= j;k++){

                cout << ar[k] << " ";
            }
            cout << "\n";
        }
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n;i++){
        cin >> ar[i];
    }
    gen_subarray(ar, n);
    return 0;
}