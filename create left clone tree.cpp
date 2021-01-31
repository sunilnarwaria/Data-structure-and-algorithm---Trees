

 
// our structure of node
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  
  int createleftclonetree(TreeNode* root){
      
      if(root == NULL){
          return NULL:
      }
      
      int lcr = createleftclonetree(root->left);
      int rcr = createleftclonetree(root->right);
      
      TreeNode nn = new TreeNode(root->data,lcr,NULL);
      
      root ->left = nn;
      root ->right = rcr;
      
      return root;
  }
