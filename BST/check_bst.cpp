#include<iostream>
#include<queue>
#include<climits>
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
bool is_bst(node* root, int min = INT_MIN, int max = INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data>=min && root->data<=max && is_bst(root->left, min, root->data) && is_bst(root->right, root->data, max)){
        return true;
    }
    else
    {
        return false;
    }
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
int main(){
    node *root = build();

    bfs(root);
    cout << "\n";

    if(is_bst(root)){
        cout << "Yes "
             << "\n";
    }
    else{
        cout << "NO";
    }



    return 0;
}