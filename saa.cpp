// C++ program to convert a left unbalanced BST to 
// a balanced BST 
#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	char data; 
	Node* left, *right; 
}; 
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
}
/* This function traverse the skewed binary tree and 
stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes) 
{ 
	// Base case 
	if (root==NULL) 
		return; 

	// Store nodes in Inorder (which is sorted 
	// order for BST) 
	storeBSTNodes(root->left, nodes); 
	nodes.push_back(root); 
	storeBSTNodes(root->right, nodes); 
} 

/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start, 
				int end) 
{ 
	// base case 
	if (start > end) 
		return NULL; 

	/* Get the middle element and make it root */
	int mid = (start + end)/2; 
	Node *root = nodes[mid]; 

	/* Using index in Inorder traversal, construct 
	left and right subtress */
	root->left = buildTreeUtil(nodes, start, mid-1); 
	root->right = buildTreeUtil(nodes, mid+1, end); 

	return root; 
} 

// This functions converts an unbalanced BST to 
// a balanced BST 
Node* buildTree(Node* root) 
{ 
	// Store nodes of given BST in sorted order 
	vector<Node *> nodes; 
	storeBSTNodes(root, nodes); 

	// Constucts BST from nodes[] 
	int n = nodes.size(); 
	return buildTreeUtil(nodes, 0, n-1); 
} 

// Utility function to create a new node 
Node* newNode(char data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

/* Function to do preorder traversal of tree */
void preOrder(Node* node) 
{ 
	if (node == NULL) 
		return; 
	printf("%d ", node->data); 
	preOrder(node->left); 
	preOrder(node->right); 
} 

// Driver program 
int main() 
{ 

	Node* root = newNode('A'); 
	root->left = newNode('B');
    root->right = newNode('P');
    root->right->left = newNode('D');
    root->right->right = newNode('X');
    root->right->right->left = newNode('R');
    root->right->right->right = newNode('Y');
    root->right->left->left = newNode('C');
    root->right->left->right = newNode('H');
    root->right->left->right->left = newNode('G');
    root->right->left->right->right = newNode('K');
    root->right->left->right->right->left = newNode('I');
    root->right->left->right->right->right = newNode('K');
    root->right->left->right->right->left->right = newNode('J');


    root = buildTree(root); 

	printf("Postorder traversal of balanced "
			"BST is : \n"); 
    printPostorder(root);

	return 0; 
} 
