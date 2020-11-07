#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ar[1000];
    for (int i = 0; i < n;i++){
        cin >> ar[i];
    }
    sort(ar, ar + n);
    int key;
    cin >> key;
    for (int p = 0; p < n;p++){
        key -= ar[p];
        int i = p+1;
        int j = n - 1;
        while (i < j)
        {
            int cur_sum = ar[p] + ar[j];
            //cout << cur_sum<<"\n";
            if (cur_sum > key)
                j--;
            else if (cur_sum < key)
                i++;
            else if (cur_sum == key)
            {
                cout <<ar[p]<<", " <<ar[i] << " and " << ar[j] << "\n";
                i++;
                j--;
            }
        }
    }
    return 0;
}