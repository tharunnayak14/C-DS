#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    // constructor for creating new node given some int data
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void bfs(node *root)
{
    // node as we are using nodes
    queue<node *> q;
    // push the root into the queue
    q.push(root);
    // traversing the queue
    while (!q.empty())
    {

        //pick one node at the front
        node *f = q.front();
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
    node *root = new node(d); // creating root
    root->left = build_tree();

    root->right = build_tree();

    return root;
}

int main()
{
    node *root = build_tree();
    //8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    //example input

    bfs(root);
    return 0;
}