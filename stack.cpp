#include <bits/stdc++.h>
using namespace std;
int ar[10],t=0;
bool isempty(){
if(t<0)
return true;
else
return false;
}
void push(int k){
++t;
ar[t-1] = k;
cout<<k<<" "<<"is pushed into stack\n";
}
void pop(){
int temp;
temp = ar[t-1];
--t;
cout<<ar[t]<<" Element is popped"<<"\n";
}
int top(){
return ar[t-1];
}
void print(int t){
for(int i=0;i<t;i++){
cout<<ar[i]<<"\n";
}
}
int main() {
cout<<"Enter size of satck\n";
cin>>t;
cout<<"Enter the elements of the stack\n";
for(int i=0;i<t;i++){
cin>>ar[i];
}
cout<<isempty()<<"\n";
push(31);
push(13);
push(3);
pop();
cout<<"Top element is"<<" "<<top()<<"\n";

print(t);
return 0;
}
