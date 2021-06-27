
 int maxdiadepth = 0;
    
    int dfs(TreeNode* root){        
        if(root == NULL) return 0;
        
        int leftdepth = dfs(root->left);
        int rightdepth = dfs(root->right);
        
        if(leftdepth + rightdepth > maxdiadepth) maxdiadepth = leftdepth + rightdepth;
        return max(leftdepth +1, rightdepth + 1);     
    }
    
    int diameterOfBinaryTree(TreeNode* root) {        
        dfs(root);
        
        return maxdiadepth;
    }
