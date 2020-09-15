#include<iostream>

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
void reverse(node*&head){
    node *c = head;
    node *prev = NULL;
    node *n;
    while(c!=NULL){
        // save the next node
        n = c->next;
        // point curr node to prev
        c->next = prev;
        //update
        prev = c;
        c = n;
    }
    head = prev;
}
int main(){
    node *head = take_input();
    print(head);
    reverse(head);
    print(head);
}