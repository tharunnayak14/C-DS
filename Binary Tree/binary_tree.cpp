#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
    // constructor for creating new node given some int data
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* build_tree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node * root = new node(d);// creating root
    root->left = build_tree();

    root->right = build_tree();

    return root;
}

void preorder_print(node* root){ // R L R (root left right)
    if(root == NULL){
        return;
    }
    cout <<root->data<<" ";
    preorder_print(root->left);
    preorder_print(root->right);
}

void print_inorder(node* root){ // left root right
    if(root==NULL){
        return;
    }
    print_inorder(root->left);
    cout << root->data<<" ";
    print_inorder(root->right);
}

void postorder_print(node* root){// left right root
    if(root==NULL){
        return;
    }
    postorder_print(root->left);
    postorder_print(root->right);
    cout << root->data<<" ";
}
int main(){
    node *root = build_tree();
    preorder_print(root);
    cout << "\n";
    print_inorder(root);
    cout << "\n";
    postorder_print(root);
    return 0;
}
