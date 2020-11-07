#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int max_sum = 0;
    int l = -1;
    int r = -1;
    int ar[n];
    for (int i = 0; i < n;i++){
        cin >> ar[i];
    }
    int csum[n] = {0}; // new array to find cumulative sum
    for (int i = 0; i < n;i++){
        csum[i] = csum[i - 1] + ar[i];
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {

        int cur_sum = 0;
        // print elements of current sub array(i, j)
        cur_sum = csum[j] - csum[i - 1];
        if (cur_sum > max_sum)
        {
            max_sum = cur_sum;
            l = i;
            r = j;
        }
        }
    }
    cout <<"Maximum sum is " <<max_sum << "\n";
    for (int k = l; k <= r;k++){
        cout << ar[k]<<" ";
    }
    return 0;
}