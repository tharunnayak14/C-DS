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
        left = NULL;
        right = NULL;
    }
};

void print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

void printIn(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

void printPost(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
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
            cout << f->data << " ";
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
node *build_tree_from_pre_and_in(int *pre, int *ino, int s, int e)
{
    // initialized only once very imp
    // otherwise it backtracks
    static int i = 0;
    //base case
    if (s > e)
    {
        return NULL;
    }
    // root node is pre[0]
    node *root = new node(pre[i]);

    int index = -1;
    //find the index of root in ino
    for (int j = s; j <= e; j++)
    {
        if (ino[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = build_tree_from_pre_and_in(pre, ino, s, index - 1);
    root->right = build_tree_from_pre_and_in(pre, ino, index + 1, e);

    return root;
}
int main()
{
    // preorder 1 2 3 4 8 5 6 7
    // inorder  3 2 8 4 1 6 7 5
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int ino[] = {3, 2, 8, 4, 1, 6, 7, 5};

    int n = sizeof(ino) / sizeof(int);
    node *root = build_tree_from_pre_and_in(pre, ino, 0, n - 1);
    bfs(root);

    return 0;
}