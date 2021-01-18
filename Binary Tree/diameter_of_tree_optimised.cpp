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
class Pair{
    public:
        int height;
        int diameter;
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
Pair diameter_optimised(node *root)
{
    // bottum up approach
    // H = max(h1,h2)+1;
    // d = max(h,d1,d2);
    Pair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }

    Pair left = diameter_optimised(root->left);
    Pair right = diameter_optimised(root->right);

    p.height = max(left.height,right.height) +1 ;
    p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));

    return p;

}

int main()
{
    node *root = build_tree();

    cout << diameter_optimised(root).diameter;
}