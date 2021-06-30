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
