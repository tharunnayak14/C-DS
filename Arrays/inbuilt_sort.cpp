#include<iostream>
#include<algorithm>
using namespace std;

// using comperator function for reverse sorting
bool compare(int a, int b){
    cout << "comparing " << a << " and " << b << "\n";
    return a > b; // return a < b for normal order
}
int main(){
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n;i++){
        cin >> ar[i];
    }
    sort(ar, ar+n, compare); // pass comperator function name to the sort function as parameter
    for (int i = 0; i < n;i++){
        cout << ar[i] <<" ";
    } 
    return 0;

}