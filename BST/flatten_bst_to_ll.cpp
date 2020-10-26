#include<iostream>
#include<queue>
using namespace std;

class node{

public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};


node* insert_in_BST(node* root, int d){
    // Base case
    if(root==NULL){
        return new node(d);
    }
    if(root->data<d){
        root->right = insert_in_BST(root->right, d);
    }
    else if(root->data>=d){
       root->left =  insert_in_BST(root->left, d);
    }
    return root;
}
node* build(){
    int d;
    cin >> d;
    node *root = NULL;
    while(d!=-1){
        root = insert_in_BST(root, d);
        cin >> d;
    }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
class linked_list{
public:
    node *head;
    node *tail;

};
linked_list flatten(node* root){
    linked_list l;
    //for empty tree
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }
    //leaf node
    if(root->left==NULL && root->right==NULL){
        l.head = l.tail = root;
        return l;
    }
    //left is not null
    if(root->left!=NULL && root->right==NULL){
        linked_list left_side = flatten(root->left);

        left_side.tail->right = root;

        l.head = left_side.head;
        l.tail = root;
        return l;
    }
    //right is not null
    if(root->right!=NULL && root->left==NULL){
        linked_list right_side = flatten(root->right);

        root->right = right_side.head;
        l.head = root;
        l.tail = right_side.tail;
        return l;
    }
    // both sides not null

     linked_list left_side = flatten(root->left);
     linked_list right_side = flatten(root->right);

     left_side.tail->right = root;

     root->right = right_side.head;

     l.head = left_side.head;
     l.tail = right_side.tail;

     return l;
}
int main(){
    node *root = build();

    bfs(root);
    cout << "\n";
    linked_list l = flatten(root);
    node *temp = l.head;

    while(temp!=NULL){
        cout << temp->data << " -> ";
        temp = temp->right;
    }

    return 0;
}