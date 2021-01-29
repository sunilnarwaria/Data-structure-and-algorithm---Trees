// iterative preorder
// hint :- right child stack mai push krte jao
#include <bits/stdc++.h>
using namespace std;
 
// Tree Node
struct Node {
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
 
// Iterative function to do Preorder traversal of the tree
void preorderIterative(Node* root)
{
    if (root == NULL)
        return;
 
    stack<Node*> st;
 
    // start from root node (set current node to root node)
    Node* curr = root;
 
    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) {
            cout << curr->data << " ";
 
            if (curr->right)
                st.push(curr->right);
 
            curr = curr->left;
        }
 
        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}
 
// Driver Code
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(70);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->left->left->right = new Node(80);
 
    preorderIterative(root);
 
    return 0;
}




// iterative inorder
// isme right chld puh krte jao

#include <iostream>
#include <stack>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
    Node (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 

void inOrderTraversal(Node *root)
{
	// Create an empty stack.
	stack<Node*> stack;

	// Start from the root node.
	Node *curr = root;

	// If the current node is null and stack is also empty, the algorithm terminates.
	while (!stack.empty() || curr != NULL)
	{
    // Push the current node to the stack and set current=current->left.
		if (curr != NULL)
		{
			stack.push(curr);
			curr = curr->left;
		}
		else // If the curr node is NULL.
		{
			curr = stack.top(); 
			stack.pop(); // Pop the node on top of stack.
			cout << curr->data << " "; // Print it.
			curr = curr->right; 
		}
	}
}

// Driver code
int main() {
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
    inOrderTraversal(root);
  return 0;
}
