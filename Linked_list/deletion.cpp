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
int length(node * head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}
void insert(node*&head, int d){ // pass by ref so that copy is not created
    if(head==NULL){
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}
void deleteHead(node*&head){
    if(head==NULL){
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}
void deleteTail(node*&head){
    if(head==NULL)
        return;
    else if(head->next==NULL){
        delete head;
        return;
    }
    node *prev = head;
    while(prev->next->next!=NULL){
        prev = prev->next;
    }
    delete (prev->next);
    prev->next = NULL;
    return;
}
void deleteMid(node*&head, int pos){
    if(head==NULL or pos==0){
        deleteHead(head);
    }
    else if (pos>length(head))
    {
        deleteTail(head);
    }
    int jump = 1;
    node *n = head;
    while(jump<=pos-1){
        n = n->next;
        jump++;
    }
    node *prev = head;
    while(prev->next!=n){
        prev = prev->next;
    }
    prev->next = n->next;
    delete n;
    return;
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
    insert(head, 4);
    insert(head, 3);
    insert(head, 5);
    insert(head, 2);
    print(head);
    deleteMid(head, 4);
    print(head);
}
