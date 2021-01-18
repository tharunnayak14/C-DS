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

int height_of_tree(node* root){
    if(root==NULL){
        return 0;
    }
    int l = height_of_tree(root->left);
    int r = height_of_tree(root->right);

    return max(l, r) + 1;
}
void print_kth_level(node* root, int k){

    if(root==NULL){
        return;
    }
    if(k==1){
        cout << root->data<<" ";
        return;
    }
    print_kth_level(root->left, k - 1);
    print_kth_level(root->right, k - 1);

}
void levelorder_print(node* root, int k){
    int i = 1;
    while(i<=k){
        print_kth_level(root, i);
        cout<<endl;
        i++;
    }
}
int main(){
    node *root = build_tree();
    //8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    //example input

    cout << height_of_tree(root) << "\n";
    levelorder_print(root, height_of_tree(root));
    return 0;

}