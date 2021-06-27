 void flatten(TreeNode* root) {
          
         if (root == NULL) return;
        while (root != NULL) {
            TreeNode* left = root->left;
            if (left != NULL) {
                while (left->right != NULL) {
                    left = left->right;
                }
                left->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
