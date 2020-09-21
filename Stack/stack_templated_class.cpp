#include<iostream>
#include<vector>

using namespace std;
template <typename T>
class stack{
private:
    vector<T> v;
public:
    void push(T data){
        v.push_back(data);
    }
    bool isempty(){
        return (v.size() == 0);
    }
    void pop(){
        v.pop_back();
    }
    T top(){
        return v.back();
    }

};
int main(){

    stack<int> s;
    for (int i = 1; i < 6;i++){
        s.push(i * i);
    }
    while(!s.isempty()){
        cout << s.top() << "\n";
        s.pop();
    }

        return 0;
}