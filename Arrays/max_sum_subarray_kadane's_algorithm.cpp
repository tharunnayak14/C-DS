#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cur_sum =0, max_sum = 0;
    int ar[n];
    for (int i = 0; i < n;i++){
        cin >> ar[i];
    }
    // kadane's algorithm for maximum sum in subarray
    for (int i = 0; i < n;i++){
        cur_sum += ar[i];
        if(cur_sum<0)
            cur_sum = 0;
        max_sum = max(cur_sum, max_sum);
    }
        cout << "Maximum sum is " << max_sum << "\n";
    return 0;
}