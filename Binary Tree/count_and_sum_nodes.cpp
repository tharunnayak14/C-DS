#include<iostream>
#include<queue>
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
int count_nodes(node* root){
    if(root==NULL){
        return 0;
    }
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);

    return l + r + 1;
}
int sum_nodes(node * root){
    if(root==NULL){
        return 0;
    }

    int sum = root->data;

    int l = sum_nodes(root->left);
    int r = sum_nodes(root->right);

    return l + r + sum;
}
int main(){
    node *root = build_tree();
    //8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    //example input
    cout<<count_nodes(root)<<"\n";
    cout << sum_nodes(root);
    return 0;

}