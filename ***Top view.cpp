
// C++ program to print top
// view of binary tree
#include <bits/stdc++.h>
using namespace std;

// Structure of binary tree
struct Node {
	Node* left;
	Node* right;
	int data;
};

// function to create a new node
Node* newNode(int key)
{
	Node* node = new Node();
	node->left = node->right = NULL;
	node->data = key;
	return node;
}

// function should print the topView of
// the binary tree
void topView(struct Node* root)
{
	// Base case
	if (root == NULL) {
		return;
	}

	// Take a temporary node
	Node* temp = NULL;

	// Queue to do BFS
	queue<pair<Node*, int> > q;

	// map to store node at each vartical distance
	map<int, int> mp;

	q.push({ root, 0 });

	// BFS
	while (!q.empty()) {

		temp = q.front().first;
		int d = q.front().second;
		q.pop();

		// If any node is not at that vertical distance
		// just insert that node in map and print it
		if (mp.find(d) == mp.end()) {
			cout << temp->data << " ";
			mp[d] = temp->data;
		}

		// Continue for left node
		if (temp->left) {
			q.push({ temp->left, d - 1 });
		}

		// Continue for right node
		if (temp->right) {
			q.push({ temp->right, d + 1 });
		}
	}
}

// Driver Program to test above functions
int main()
{
	/* Create following Binary Tree
		1
		/ \
		2 3
		\
		4
		\
		5
			\
			6*/
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);
	cout << "Following are nodes in top view of Binary Tree\n";
	topView(root);
	return 0;
}
