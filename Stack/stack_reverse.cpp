#include<iostream>
#include<vector>
#include<stack>

using namespace std;
void transfer(stack<int>&s, stack<int>&p, int n){
        for (int i = 0; i < n;i++){
            p.push(s.top());
            s.pop();
        }
}
void reverse(stack<int>&s){
    stack<int> p;
    int n = s.size();
    for (int i = 0; i < n;i++){
        //store top
        int x = s.top();
        s.pop();
        //transfer every element to new stack
        transfer(s, p, n-1-i);
        //push stored top into stack
        s.push(x);
        //transfer elements back into stack from new stack
        transfer(p, s, n-i-1);
    }
}
int main(){

    stack<int> s;
    for (int i = 1; i < 6;i++){
        s.push(i * i);
    }
    reverse(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";

    return 0;
}