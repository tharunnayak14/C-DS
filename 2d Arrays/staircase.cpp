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
    int key;
    cin >> key;
    int i = 0;
    int j = n - 1;
    while(ar[i][j]!=key){
        if(ar[i][j]<key){
            i++;
        }
        else if (ar[i][j]>key){
            j--;
        }
        if(ar[i][j]==key){
            cout << i << " " << j;
            break;
        }
    }
    return 0;
}