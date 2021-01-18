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
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int dleft, droot, dright;
    // 3 variables for 3 cases
    //  O(n^2) solution as it is calculating height for every node
    droot = h1 + h2;
    dleft = diameter(root->left);
    dright = diameter(root->right);
    return (max(dleft, max(dright, droot)));
}

int main()
{
    node *root = build_tree();

    cout << diameter(root);
}