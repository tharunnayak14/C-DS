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
int lenght(node * head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}
void insertMiddle(node*&head, int d, int pos){
    if(head==NULL or pos==0){
        insert(head, d);
    }
    else if (pos>lenght(head))
    {
        insertTail(head, d);
    }
    else{
        int jump = 1;
        node *temp = head;
        while(jump<=pos-1){
            temp = temp->next;
            jump++;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

/* pass by value cuz if we pass by ref head becomes NULL after one iteraton so when we try printing again it wont work , so if we pass by value only copyof head changes*/

void print(node* head){
    while(head!=NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "\n";
}
int main(){
    node *head = NULL;
    insert(head, 4);
    insert(head, 3);
    insert(head, 5);
    insert(head, 2);
    print(head);
    insertMiddle(head, 7898, 3);
    print(head);
    insertMiddle(head, 78, 1);
    print(head);
    insertTail(head, 6);
    insertTail(head, 9);
    insertTail(head, 80);
    print(head);
}