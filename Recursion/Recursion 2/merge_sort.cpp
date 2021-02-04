#include<iostream>
using namespace std;
void merge(int ar[], int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];
    while(i<=mid && j<=e){
        if(ar[i]<ar[j]){
            temp[k++] = ar[i++];
        }
        else{
            temp[k++] = ar[j++];
        }
    }
    while(i<=mid){
        temp[k++] = ar[i++];
    }
    while(j<=e){
        temp[k++] = ar[j++];
    }
    for (int i = s; i <= e;i++){
        ar[i] = temp[i];
    }
}
void merge_sort(int  ar[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s + e) / 2;
    merge_sort(ar, s, mid);
    merge_sort(ar, mid + 1, e);
    merge(ar, s, e);
}
int main(){
    int ar[] = {1, 2, 23, 4, 35, 67, 789, 342, 65, 656, 79, 0};
    int n = sizeof(ar) / sizeof(int);
    merge_sort(ar, 0,n-1);
    for (int i = 0; i < n;i++){
        cout << ar[i] << " ";
    }

        return 0;
}