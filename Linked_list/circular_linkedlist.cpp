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
void print(node*head){
    node *temp = head;
    while(temp->next!=head){
        cout << temp->data << " ->";
        temp = temp->next;
    }
    cout << temp->data << "\n";
    return;
}
int main(){
    node *head = NULL;
    insert_at_head(head, 5);
    insert_at_head(head, 2);
    insert_at_head(head, 3);
    insert_at_head(head, 1);
    insert_at_head(head, 8);
    print(head);
    return 0;
}