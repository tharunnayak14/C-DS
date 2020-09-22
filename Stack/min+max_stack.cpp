#include<iostream>
#include<vector>
using namespace std;
class stack{
private:
    vector<int> v;
    vector<int> max_stack;
    vector<int> min_stack;
public:
    int top(){
        return v.back();
    }
    void push(int data){
        int cur_min = data;
        int cur_max = data;
        v.push_back(data);

        if(min_stack.size()){
            cur_min = min(min_stack[min_stack.size() - 1],data);
            cur_max = max(max_stack[max_stack.size() - 1], data);
        }
        min_stack.push_back(cur_min);
        max_stack.push_back(cur_max);
        v.push_back(data);
    }
    int getmin(){
        return min_stack.back();
    }
    int getmax(){
        return max_stack.back();
    }

};
int main(){

    stack s;
    s.push(1);
        s.push(5);
            s.push(8);
                s.push(6);
                    s.push(3);
                    cout<<s.getmax()<<"\n";
                    cout<<s.getmin();

                    return 0;
}