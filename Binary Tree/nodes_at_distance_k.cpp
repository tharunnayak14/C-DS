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
void print_level_k(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    print_level_k(root->left, k - 1);
    print_level_k(root->right, k - 1);
    return;
}
int nodes_at_distance_k(node *root, node *target, int k)
{
    //base case
    if (root == NULL)
    {
        return -1;
    }
    // reached the target
    if (root == target)
    {
        print_level_k(target, k);
        return 0;
    }
    // back to anscestor
    // left subtree
    int dl = nodes_at_distance_k(root->left, target, k);
    if (dl != -1)
    {
        // 2 cases
        // ancestor itslef or go right

        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            // go to right hand side
            print_level_k(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    // right subtree
    int dr = nodes_at_distance_k(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            // go to left hand side
            print_level_k(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
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
    node* target = root->left->left;

    bfs(root);
    cout<<endl;
    nodes_at_distance_k(root,target,4);

    return 0;
}