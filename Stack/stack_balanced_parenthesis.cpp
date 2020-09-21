#include<iostream>
#include<stack>
using namespace std;
bool is_balanced(char * str){
    stack<char> s;

    for (int i = 0; str[i] != '\0';i++){
        char ch = str[i];
        if(ch=='('){
            s.push(ch);
        }
        else if(ch==')'){
            if(s.empty() or s.top()!='('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}
int main(){
    char str[100] = "(a+c-d))";
    cout<<is_balanced(str);
}