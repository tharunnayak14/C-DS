#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
};
class queue{
public:
    node *front, *rear;
    queue(){
        front = rear = NULL;
    }
    void push(int d){
       node* temp = new node(d); 
        if (rear == NULL) { 
            front = rear = temp; 
            return; 
        } 
        rear->next = temp; 
        rear = temp; 
    }
    void pop(){
        if (front == NULL) 
            return; 
        node* temp = front; 
        front = front->next;

        if (front == NULL) 
            rear = NULL; 
  
        delete (temp); 
    }
};

int main(){
    queue q;
    q.push(3);
    q.push(88);
    q.push(8);
    cout << q.front->data<<"\n";
    cout << q.rear->data<<"\n";
    q.pop();
    cout << q.front->data<<"\n";
    cout << q.rear->data;
}