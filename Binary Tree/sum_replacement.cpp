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
int sum_replacement(node *&root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }
    int sum = root->data;
    int l_sum = sum_replacement(root->left);
    int r_sum = sum_replacement(root->right);

    root->data = l_sum + r_sum;

    return l_sum + sum + r_sum;
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

    sum_replacement(root);
    cout<<"After sum replacement:"<<endl;

    bfs(root);
}