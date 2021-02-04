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
void preorder(node* root){
    if(root==NULL){
        return;
    }
        cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ar[10000];
        for (int i = 0; i < n;i++){
            cin >> ar[i];
        }
        node *root = build_tree_from_array(ar, 0, n - 1);
        preorder(root);
        cout << "\n";
    }

    return 0;
}