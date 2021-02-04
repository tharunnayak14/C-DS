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
int main()
{

    vector<int> pre_order = {5, 3, 1, 7, 6, 8};
    int min_index = min_element(pre_order.begin(), pre_order.end()) - pre_order.begin();
    // cout << min_index << endl;
    vector<int> inorder;
    int count = min_index;
    for (auto it = pre_order.begin() + min_index; count >= 0; it--)
    {
        inorder.push_back(*it);
        count--;
    }
    sort(pre_order.begin() + min_index, pre_order.end());
    for (auto it = pre_order.begin() + min_index + 1; it != pre_order.end(); it++)
    {
        inorder.push_back(*it);
    }
    // for (auto x : inorder)
    // {
    //     cout << x << " ";
    // }
    int n = pre_order.size();
    int pre[n];
    int ino[n];
    for(int i=0;i<n;i++){
        pre[i] = pre_order[i];
        ino[i] = inorder[i];
    }

    node *root = build_tree_from_pre_and_in(pre, ino, 0, n - 1);
    bfs(root);
}