#include<iostream>
#include<vector>

using namespace std;
// generalize the code for all data types
template <typename T>
class stack{
private:
    // using data of type T
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
    // we should specify data type
    // stack<T> s;
    stack<int> s;
    for (int i = 1; i < 6;i++){
        s.push(i * i);
    }
    while(!s.isempty()){
        cout << s.top() << " ";
        s.pop();
    }
    
    cout<<endl;

    stack<char> c;
    for (char i = 65; i < 80;i++){
        c.push(i);
    }
    while(!c.isempty()){
        cout << c.top() << " ";
        c.pop();
    }

    return 0;
}
