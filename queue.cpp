#include<bits/stdc++.h>
using namespace std;
# define MAX 10
int ar[MAX];
int rear = -1;
int first = -1;
bool isempty(){
    if(first == -1 && rear == -1)
        return true;
    else
        return false;
}
bool isfull(){
    if(rear == MAX -1)
        return true;
    else
        return false;
}
int push(int n){
    if(rear == MAX-1){
        cout<<"OVER FLOW\n";
    }
    else{
        if(first == -1){
            first = 0;
        }
        ++rear;
        ar[rear]=n;
    }
}
int pop(){
    if(isempty()){
        cout<<"QUEUE IS EMPTY\n";
    }
    else if( first == rear ){
        first = rear  = -1;
    }
    else
        ++first;
}
int show_front(){
    if(isempty()){
        cout<<"QUEUE IS EMPTY\n";
    }
    else{
        cout<<"FRONT ELEMENT IS "<<ar[first]<<" \n";
    }
}
void display()
{
 if(isempty())
  cout<<"Queue is empty\n";
 else
 {
  int i;
  if( first <= rear )
  {
   for( i=first ; i<= rear ; i++)
   cout<<ar[i]<<" ";
  }
  else
  {
   i=first;
   while( i < MAX)
   {
   cout<<ar[i]<<" ";
   i++;
   }
   i=0;
   while( i <= rear)
   {
   cout<<ar[i]<<" ";
   i++;
   }
  }
 }
}


int main(){
    push(2);
    push(3);
    display();
    return 0;
}
