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

node * build_balanced_tree(int *a, int s,int e){
    //base case
    if(s>e){
        return NULL;
    }
    //find mid point and make it root
    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    // now recursievly build both left and right subtrees
    root->left = build_balanced_tree(a, s, mid - 1);
    root->right = build_balanced_tree(a, mid + 1, e);

    return root;
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
            cout<<f->data<<" ";
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
int main(){

    int ar[] = {1, 2, 3, 4, 5,  6, 7,8,9,10,23};

    node *root = build_balanced_tree(ar, 0, 10);
    bfs(root);

    return 0;
}