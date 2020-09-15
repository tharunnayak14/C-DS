#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node(int d){ // parametrised constructor
            data = d;
            next = NULL;
        }
};
void insert(node*&head, int d){ // pass by ref so that copy is not created
    if(head==NULL){
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}
void insertTail(node*&head, int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node *tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}
void print(node* head){
    while(head!=NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "\n";
}
node* take_input(){
    int d;
    cin >> d;
    node *head = NULL;
    while(d!=-1){
        insert(head, d);
        //insertTail(head, d);
        cin >> d;
    }
    return head;
}
node* midpoint(node* head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while(fast->next!=NULL and fast!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node * merge(node * a, node * b){
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    node *c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }

    return c;
}
node * merge_sort(node * head){
    if(head->next==NULL or head==NULL){
        return head;
    }
    // break about mid
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;
    // sort
    a = merge_sort(a);
    b = merge_sort(b);
    //merge
    node *c = merge(a, b);

    return c;
}
int main(){
    node *head = take_input();
    print(head);
    node * newhead = merge_sort(head);
    print(newhead);
}