 void BstToGst(TreeNode* root,int &sum){
        
        if(root == NULL){
            return;
        }
        BstToGst(root->right,sum);
        root->val = root->val + sum;
        sum = root->val;
        BstToGst(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        BstToGst(root,sum);
     return root;
         
    }
