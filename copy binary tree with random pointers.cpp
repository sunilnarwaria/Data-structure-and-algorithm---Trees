
Node* util(Node* root) {  // this bascially makes all new nodes to the left of the original node
    if (!root) return root;
    Node* tl = root->left, * tr = root->right;
    root->left = new Node(root->data);
    root->right = nullptr;
    root->left->left = util(tl);
    root->left->right = util(tr);
    return root; // so the series becomes old node then new node then old then new and so on
}
     //   1                           1 (old)
     // /   \       --->            /
     //2     3                     1 (new)
     //                          /   \
     //                    (old)2     3 (old)
     //                        /      /
     //                  (new)2      3(new)

void ran(Node* root) {// here I connect all the random nodes (as the old nodes points to the random old nodes) and the new copy of these nodes lie on the left of each node.
                      //so we just connect them.
    if (!root) return;
    if (root->random) root->left->random = root->random->left;
    ran(root->left->left);
    ran(root->left->right);
}

Node* detach(Node* root) { // here we detach the new formed tree from the original tree
    if (!root) return nullptr;
    Node* new_root = root->left;
    root->left = new_root->left;
    root->right = new_root->right;
    new_root->left = detach(new_root->left);
    new_root->right = detach(new_root->right);
    return new_root;
}

Node* cloneTree(Node* root) { // main function
    root = util(root);
    ran(root);
    return detach(root);
}
