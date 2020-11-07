#include<iostream>
using namespace std;

// using comperator function for reverse sorting
bool compare(int a, int b){
    cout << "comparing " << a << " and " << b << "\n";
    return a > b; // return a < b for normal order
}
void bubble_sort(int ar[],int n, bool (&cmp)(int a, int b)){
    for (int i = 0; i < n;i++){
        for (int j = 0; j <= (n-1-i);j++){
            if(cmp(ar[j],ar[j+1])){
                swap(ar[j], ar[j + 1]);
            }
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
    bubble_sort(ar, n,compare);
    for (int i = 0; i < n;i++){
        cout << ar[i] <<" ";
    } 
    return 0;

}