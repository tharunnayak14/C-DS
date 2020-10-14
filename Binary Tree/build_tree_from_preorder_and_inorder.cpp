#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printIn(node*root){
    if(root==NULL){
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node*root){
    if(root==NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
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



node* buildTreeFromArray(int *a,int s,int e){
    //Base Case
    if(s>e){
        return NULL;
    }
    //Recursive Case
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildTreeFromArray(a,s,mid-1);
    root->right = buildTreeFromArray(a,mid+1,e);
    return root;

}

int main(){
    // preorder 1 2 3 4 8 5 6 7 
    // inorder  3 2 8 4 1 6 7 5
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int ino[] = {3, 2, 8, 4, 1, 6, 7, 5};

    int n = sizeof(ino) / sizeof(pre);

    node *root = create_tree(ino, pre, 0, n-1);
    print_inorder(root);

    return 0;
}