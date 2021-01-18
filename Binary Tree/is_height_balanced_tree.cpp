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
class hb_pair
{
public:
    int height;
    bool balance;
};
node *build_tree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *f = new node(d);
    f->left = build_tree();
    f->right = build_tree();

    return f;
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);

    return max(l, r) + 1;
}
hb_pair is_height_balanced(node *root)
{
    hb_pair p;
    // null tree is always balanced
    if (root == NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }
    // traverse using post order
    hb_pair left = is_height_balanced(root->left);
    hb_pair right = is_height_balanced(root->right);
    
    p.height = max(left.height, right.height) + 1;
    if (abs(left.height - right.height) <= 1 && left.balance && right.balance)
        p.balance = true;
    else
        p.balance = false;

    return p;
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
int main()
{
    node *root = build_tree();
    bfs(root);
    hb_pair p = is_height_balanced(root);
    if (p.balance)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
}