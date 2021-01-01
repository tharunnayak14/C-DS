#include<iostream>
#include<climits>
using namespace std;
int max_sub_sum(int ar[][100], int n, int m){
    int sum = INT_MIN;
    // col wise
    for (int i = n-1; i >=0;i--){
        for (int j = m-2; j >=0;j--){
            ar[i][j] += ar[i][j + 1];
        }
    }

    // row wise
    for (int i = m-1; i >=0;i--){
        for (int j = n-2; j >=0;j--){
            ar[j][i] += ar[j + 1][i];
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            sum = max(sum, ar[i][j]);
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

    cout<<max_sub_sum(ar, n, m);
    return 0;
}