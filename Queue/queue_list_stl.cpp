#include<iostream>
#include<list>
using namespace std;

class queue{
    list<int> l;
    int cur_size;
public:
    queue(){
        cur_size = 0;
    }
    bool isempty(){
        return cur_size == 0;
    }
    void push(int data){
        l.push_back(data);
        cur_size += 1;
    }
    void pop(){
        if(!isempty()){
            l.pop_front();
            cur_size--;
        }
    }
    int get_front(){
        return l.front();
    }
};

int main(){
    queue q;
    for (int i = 1; i < 10;i++){
        q.push(i);
    }
    while(!q.isempty()){
        cout << q.get_front() << " ";
        q.pop();
    }
}