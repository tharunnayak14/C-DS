#include <bits./stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insert_head(node*&head, int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node* n =  new node(d);
    n->next = head;
    head = n;
    return;
}
node * take_input(){
    int d;
    node * head = NULL;
    while(cin>>d){
        insert_head(head, d);
    }
    return head;
}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void reverse(node*& head){
    node* prev = NULL;
    node* c=  head;
    node*  n;
    while(c!=NULL){
        n = c->next;
        c->next = prev;
        prev = c;
        c= n;
    }
    head = prev;
}
node* recursive_reverse(node*& head){

    // O(n) complexity + O(n) stack space
    if(head->next==NULL){
        return head;
    }
    // rec case

    node*shead = recursive_reverse(head->next);

    // node * temp =shead;
    // while (temp->next!=NULL)
    // {
    //     temp = temp->next;
    // }
    node * temp = head->next;
    head->next =  NULL;
    temp->next =  head;

    return shead;
    
}
int main(){

    node* head = take_input();

    print(head);

    head = recursive_reverse(head);

    print(head);

    return 0;
}