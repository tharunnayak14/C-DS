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
void insert_at_tail(node*&head, int data){
    if(head==NULL){
        head = new node(data);
        head->next = head;
        return;
    }
    node *n = new node(data);
    node*temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;

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
int main(){
    node *head = NULL;
    insert_at_tail(head, 4);
    print(head);
    insert_at_head(head, 5);
    print(head);
    insert_at_head(head, 2);
    print(head);
    insert_at_head(head, 3);
    print(head);
    insert_at_head(head, 1);
    print(head);
    insert_at_head(head, 8);
    print(head);
    insert_at_tail(head, 6);
    print(head);
    insert_at_tail(head, 90);
    print(head);
    return 0;
}
