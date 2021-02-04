#include<iostream>
using namespace std;
int first_occurance(int key, int ar[], int n){
    if(n==0){
        return -1;
    }
    if(ar[0]==key){
        return 0;
    }
    int i = first_occurance(key, ar + 1, n - 1);
    if(i==-1){
        return -1;
    }
    return i + 1;
}
int last_occurance(int ar[], int n, int key){
    if(n==0){
        return -1;
    }
    if(ar[n-1]==key){
        return n - 1;
    }
    else{
        return last_occurance(ar, n-1, key);
    }
    return -1;
}
void all_occurances(int ar[], int n, int key, int i){
    if(i==n){
        return;
    }
    if(ar[i]==key){
        cout << i << " ";
    }
    all_occurances(ar, n, key, i + 1);
}
int main(){
    int ar[] = {1, 2, 3, 4, 5, 5, 6, 6, 7, 7,7,7, 7, 8};
    int n = sizeof(ar) / sizeof(int);
    int key;
    cin >> key;
    cout<<first_occurance(key,ar, n)<<"\n";
    cout << last_occurance(ar, n, key)<<"\n";
    all_occurances(ar, n, key, 0);

}