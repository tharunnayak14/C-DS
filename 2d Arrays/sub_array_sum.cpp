#include<iostream>
using namespace std;
int sub_sum(int ar[][100], int n, int m){
    int sum = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            sum += ar[i][j] * ((i + 1) * (j + 1) * (n - i) * (m - j));
        }
    }
    return sum;
}
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int ar[100][100];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> ar[i][j];
        }
    }
    cout<<sub_sum(ar, n, m);
    return 0;
}