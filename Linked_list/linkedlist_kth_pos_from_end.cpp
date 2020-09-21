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
node* kth_pos_from_end(node* head, int k){
    if(head==NULL or head->next==NULL){
        return head;
    }
    node *slow = head;
    node *fast;
    while(k--){
        fast = fast->next;
    }
    //cout << fast->data << "\n";
    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main(){
    node *head = take_input();
    print(head);
    node* k = kth_pos_from_end(head, 2);
    cout << k->data;

}