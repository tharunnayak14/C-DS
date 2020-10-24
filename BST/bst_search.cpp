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

// complexity O(height of tree)
bool search(node* root, int key){
    // base case 
    if(root->data==key){
        return true;
    }
    if(root==NULL){
        return false;
    }
    //rec case
    if(key>root->data){
        return search(root->right, key);
    }
    else if(key<=root->data){
        return search(root->left, key);
    }

}
int main(){
    node *root = build();

    bfs(root);
    cout << "\n";

    int key;
    cin >> key;
    if(search(root, key)){
        cout << "found"
             << "\n";
    }
    else{
        cout << "not found";
    }

    return 0;
}