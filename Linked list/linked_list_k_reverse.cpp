#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};
void insert_tail(node*&head,int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new node(d);
    return;
}
node* take_input(){
    int d;
    node* head = NULL;
    while(cin>>d){
        insert_tail(head,d);
    }
    return head;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}
node* linked_list_k_reverse(node*&head, int n, int k){
    node* prev = NULL;
    node* c=  head;
    node* n;
    int count =0;
    
}
int main(){
    int n,k;
    cin>>n>>n;
    node* head = take_input();
    
}