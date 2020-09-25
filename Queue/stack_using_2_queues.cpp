#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
//templated class
template<typename t> 
class stack{
private:
    queue<t> q1;
    queue<t> q2;
public:
    void push(t data){
        q1.push(data);
    }
    int size(){
        return q1.size() + q2.size();
    }
    bool isempty(){
        return size()==0;
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        // remove size-1 elements from q1 and push them to q2
        while (q1.size()>1){
            q2.push(q1.front());
            q1.pop();

        }

        // pop the last element from q1
        q1.pop();

        //swap q1 and q2
        swap(q1,q2);

    }
    int top(){
        while (q1.size()>1){
                q2.push(q1.front());
                q1.pop();

        }
        t top_element = q1.front();
        q1.pop();
        q2.push(top_element);

        swap(q1, q2);

        return top_element;
    }
};


int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    while (!s.isempty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}