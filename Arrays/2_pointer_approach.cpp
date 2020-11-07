#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n;i++){
        cin >> ar[i];
    }
    sort(ar, ar + n);
    int key = 10;
    int i = 0;
    int j = n - 1;
    while (i<j)
    {
        int cur_sum = ar[i] + ar[j];
        //cout << cur_sum<<"\n";
        if(cur_sum>key)
           j--;
        else if(cur_sum<key)
           i++;
        else if (cur_sum==key){
            cout << ar[i] << " " << ar[j] << "\n";
            i++;
            j--;
        }
        
    }
    return 0;
}