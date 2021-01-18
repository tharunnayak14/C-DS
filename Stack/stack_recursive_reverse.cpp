#include<iostream>
#include<vector>
#include<stack>

using namespace std;
void insertbottom(stack<int>&s, int x){
// base case
    if(s.empty()){
        s.push(x);
        return;
    }
    int data = s.top();
    s.pop();
    insertbottom(s, x);
    s.push(data);
}
void reverse_recursive(stack<int>&s){
    if(s.empty()){
        return;
    }
    //pop the top and insert it at bottom of reversed smaller stack
    int x = s.top();
    s.pop();
    //rec reverse smaller stack
    reverse_recursive(s);
    insertbottom(s,x);
}
int main(){

    stack<int> s;
    int n;
    cin>>n;
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        s.push(k);
    }
    reverse_recursive(s);
    while(!s.empty()){
        cout << s.top() <<endl;
        s.pop();
    }


    return 0;
}