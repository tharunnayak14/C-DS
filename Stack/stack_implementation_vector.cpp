#include<iostream>
#include<vector>

using namespace std;

class stack{
private:
    vector<int> v;
public:
    void push(int data){
        v.push_back(data);
    }
    bool isempty(){
        return (v.size() == 0);
    }
    void pop(){
        v.pop_back();
    }
    int top(){
        return v.back();
    }

};
int main(){

    stack s;
    for (int i = 1; i < 6;i++){
        s.push(i * i);
    }
    while(!s.isempty()){
        cout << s.top() << "\n";
        s.pop();
    }

        return 0;
}