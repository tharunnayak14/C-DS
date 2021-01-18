#include <iostream>
#include <queue>
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
node *delete_bst(int data, node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = delete_bst(data, root->left);
        return root;
    }
    else if (data == root->data)
    {
        // now found the root to be deleted
        // 3 cases arise root has either 0 or 1 or 2 children

        //case 1: 0 children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //case 2: 1 child
        //left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        //case 3: 2 children
        // find a potential replacement of a node
        // potential can be max in left subtree or min in right subtree
        // let's consider right subtree and find it's min
        node *replace_node = root->right;
        while (replace_node->left != NULL)
        {
            replace_node = replace_node->left;
        }
        //copy data of the min in right subtree to the root
        root->data = replace_node->data;
        //recursively call on the right subtree to delete the replacement node
        root->right = delete_bst(replace_node->data, root->right);
        return root;
    }
    else
    {
        root->right = delete_bst(data, root->right);
        return root;
    }
}

node *insert_in_BST(node *root, int d)
{
    // Base case
    if (root == NULL)
    {
        return new node(d);
    }
    if (root->data < d)
    {
        root->right = insert_in_BST(root->right, d);
    }
    else if (root->data >= d)
    {
        root->left = insert_in_BST(root->left, d);
    }
    return root;
}
node *build()
{
    int d;
    cin >> d;
    node *root = NULL;
    while (d != -1)
    {
        root = insert_in_BST(root, d);
        cin >> d;
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << ",";
            q.pop();

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
    node *root = build();

    bfs(root);
    cout << "\n";

    int s;
    cin >> s;

    root = delete_bst(s, root);
    bfs(root);

    return 0;
}