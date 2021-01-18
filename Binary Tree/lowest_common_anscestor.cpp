#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
node *lca(node *root, int a, int b)
{
    //base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == a or root->data == b)
    {
        return root;
    }

    // search in left and right subtrees
    node *left_ans = lca(root->left, a, b);
    node *right_ans = lca(root->right, a, b);

    if(left_ans !=NULL and right_ans!=NULL){
        return root;
    }
    if(left_ans!=NULL){
        return left_ans;
    }
    return right_ans;
}
void bfs(node *root)
{
    // node as we are using nodes
    queue<node *> q;
    // push the root into the queue
    q.push(root);
    q.push(NULL);
    // traversing the queue
    while (!q.empty())
    {
        //pick one node at the front
        node *f = q.front();

        //Printing every level on a new line
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            // to avoid infinite loop
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            //print its data
            cout << f->data << " ";
            //pop it
            q.pop();
            //if its children exist push them into the queue
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

node *build_tree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = build_tree();
    root->right = build_tree();

    return root;
}

int main()
{
    node *root = build_tree();
    bfs(root);

    node * pp  = lca(root,13,1);
    cout<<pp->data<<endl;
}