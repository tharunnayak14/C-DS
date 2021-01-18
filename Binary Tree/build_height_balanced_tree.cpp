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

node * build_tree_from_array(int *a, int s,int e){
    if(s>e){
        return NULL;
    }
    int mid = (s + e) / 2;
    node *root = new node(a[mid]);

    root->left = build_tree_from_array(a, s, mid - 1);
    root->right = build_tree_from_array(a, mid + 1, e);

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

    int ar[] = {1, 2, 3, 4, 5,  6, 7,};

    node *root = build_tree_from_array(ar, 0, 6);
    bfs(root);

    return 0;
}