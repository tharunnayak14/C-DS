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
void insert_at_head(node*&head, int data){
    node *n = new node(data);
    node *temp = head;
    n->next = head;
    if(temp!=NULL){
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = n;
    }
    else{
        n->next = n;//self loop for only one element case (important)
    }
    head = n;
}
void print(node*head){
    node *temp = head;
    while(temp->next!=head){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << "\n";
    return;
}
node * getnode(node*head, int data){
    node *temp = head;
    // all nodes except last node
    while(temp->next!=head){
        if(temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    // for last node
    if(temp->data==data){
        return temp;
    }
    return NULL;
}
void deletenode(node*&head, int data){
    node *del = getnode(head, data);
    if(del==NULL){
        return;
    }
    if(head==del){
        head = head->next;
    }
    node *temp = head;
    //one step behind node to be deleted
    while(temp->next!=del){
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
}
int main(){
    node *head = NULL;
    insert_at_head(head, 5);
    insert_at_head(head, 4);
    insert_at_head(head, 3);
    insert_at_head(head, 1);
    insert_at_head(head, 8);
    print(head);
    deletenode (head, 4);
    print(head);
    deletenode (head, 3);
    print(head);
    deletenode (head, 8);
    print(head);
    return 0;
}