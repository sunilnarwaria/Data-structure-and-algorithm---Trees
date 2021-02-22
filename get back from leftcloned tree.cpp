
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


    TreeNode* getbackfromleftcloned(TreeNode* root){
        
        if(root == NULL){
            return;
            }
        
        int lnn = getbackfromleftcloned(root->left);
        int rnn =  getbackfromleftcloned(root->right);
        
        root->left = lnn;
        root->right = rnn;
        
        return root;
    }
      
