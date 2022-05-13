class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }


/*Method 1 – Using Queue 
The following are steps to print Bottom View of Binary Tree. 
1. We put tree nodes in a queue for the level order traversal. 
2. Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue along with the horizontal distance 
as hd-1 and right child as hd+1. 
3. Also, use a TreeMap which stores key value pair sorted on key. 
4. Every time, we encounter a new horizontal distance or an existing horizontal distance put the node data for the horizontal
distance as key. For the first time it will add to the map, next time it will replace the value. This will make sure that the bottom most 
element for that horizontal distance is present in the map and if you see the tree from beneath that you will see that element.
*/
// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
	int data; //data of the node
	int hd; //horizontal distance of the node
	Node *left, *right; //left and right references

	// Constructor of tree node
	Node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};

// Method that prints the bottom view.
void bottomView(Node *root)
{
	if (root == NULL)
		return;

	// Initialize a variable 'hd' with 0
	// for the root element.
	int hd = 0;

	// TreeMap which stores key value pair
	// sorted on key value
	map<int, int> m;

	// Queue to store tree nodes in level
	// order traversal
	queue<Node *> q;

	// Assign initialized horizontal distance
	// value to root node and add it to the queue.
	root->hd = hd;
	q.push(root); // In STL, push() is used enqueue an item

	// Loop until the queue is empty (standard
	// level order loop)
	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop(); // In STL, pop() is used dequeue an item

		// Extract the horizontal distance value
		// from the dequeued tree node.
		hd = temp->hd;

		// Put the dequeued tree node to TreeMap
		// having key as horizontal distance. Every
		// time we find a node having same horizontal
		// distance we need to replace the data in
		// the map.
		m[hd] = temp->data;

		// If the dequeued node has a left child, add
		// it to the queue with a horizontal distance hd-1.
		if (temp->left != NULL)
		{
			temp->left->hd = hd-1;
			q.push(temp->left);
		}

		// If the dequeued node has a right child, add
		// it to the queue with a horizontal distance
		// hd+1.
		if (temp->right != NULL)
		{
			temp->right->hd = hd+1;
			q.push(temp->right);
		}
	}

	// Traverse the map elements using the iterator.
	for (auto i = m.begin(); i != m.end(); ++i)
		cout << i->second << " ";
}

// Driver Code
int main()
{
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	cout << "Bottom view of the given binary tree :\n"
	bottomView(root);
	return 0;
}



/*
Method 2- Using HashMap() 
This method is contributed by Ekta Goel. 

Approach: 
Create a map like, map where key is the horizontal distance and value is a pair(a, b) where a
is the value of the node and b is the height of the node. Perform a pre-order traversal of the tree. If the current node at a horizontal distance of h is the first we’ve seen, insert it in the map. Otherwise, compare the node with the existing one in map and if the height of the new node is greater, update in the Map.

Below is the implementation of the above:
*/

// C++ Program to print Bottom View of Binary Tree
#include <bits/stdc++.h>
#include <map>
using namespace std;
 
// Tree node class
struct Node
{
    // data of the node
    int data;
     
    // horizontal distance of the node
    int hd;
     
    //left and right references
    Node * left, * right;
     
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};
 
void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
    // Base case
    if (root == NULL)
        return;
     
    // If node for a particular
    // horizontal distance is not
    // present, add to the map.
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root -> data, curr);
    }
    // Compare height for already
    // present node at similar horizontal
    // distance
    else
    {
        pair < int, int > p = m[hd];
        if (p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root -> data;
        }
    }
     
    // Recur for left subtree
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m);
     
    // Recur for right subtree
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}
 
void printBottomView(Node * root)
{
     
    // Map to store Horizontal Distance,
    // Height and Data.
    map < int, pair < int, int > > m;
     
    printBottomViewUtil(root, 0, 0, m);
     
     // Prints the values stored by printBottomViewUtil()
    map < int, pair < int, int > > ::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}
 
int main()
{
    Node * root = new Node(20);
    root -> left = new Node(8);
    root -> right = new Node(22);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(25);
    root -> left -> right -> left = new Node(10);
    root -> left -> right -> right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    printBottomView(root);
    return 0;
}
