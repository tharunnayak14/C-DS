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
    cin>>d;
    node *head = NULL;
    while(d!=-1){
        insert(head, d);
        //insertTail(head, d);
        cin>>d;
    }
    return head;
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
int main(){
    node *head1 = take_input();
    node *head2 = take_input();
    print(head1);
    print(head2);
    node * newhead = merge(head1, head2);
    print(newhead);
}