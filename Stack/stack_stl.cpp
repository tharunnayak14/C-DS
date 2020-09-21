#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){

    stack<int> s;
    for (int i = 1; i < 6;i++){
        s.push(i * i);
    }
    while(!s.empty()){
        cout << s.top() << "\n";
        s.pop();
    }

        return 0;
}