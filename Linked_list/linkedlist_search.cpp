#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node(int d){
            next = NULL;
            data = d;
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
void print(node* head){
    while(head!=NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "\n";
}
// search for key in linkedlist (linear search)
bool search(node *head, int key){
    node*temp = head;
    while (temp!=NULL)
    {
        if(head->data==key){
            return true;
        }
        head = head->next;
    }
    return false;
}

// search recursive
bool search_recursive(node* head, int key){
    if(head==NULL){
        return false;
    }
    else if(head->data==key){
        return true;
    }
    else{
        return search_recursive(head->next, key);
    }
}
int main(){
    node *head = NULL;
    insert(head, 4);
    insert(head, 3);
    insert(head, 5);
    insert(head, 2);
    print(head);
    if(search_recursive(head,5)){
        cout << "Element found"
             << "\n";
    }
    else{
        cout << "not there"
             << "\n";
    }
    return 0;
}