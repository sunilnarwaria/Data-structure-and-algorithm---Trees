// Time complexity O(n) and space O(1)  
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
 

// just using preorder traversal in O(n) time and O(n) space
 // this is not efficient
 
   vector<TreeNode*> temp;
    void preorder(TreeNode* node)
    {
        if(node!=nullptr)
        {
            temp.push_back(node);
            preorder(node->left);
            preorder(node->right);
        }
    }
    void flatten(TreeNode* root) {
        preorder(root);
        for(int i=0;i<int(temp.size())-1;i++)
        {
            temp[i]->left=nullptr;
            temp[i]->right=temp[i+1];
        }
    
    }
    
