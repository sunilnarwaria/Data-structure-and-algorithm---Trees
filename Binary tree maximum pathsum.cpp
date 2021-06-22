
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans(TreeNode* root,int& maxx){

        if(root == NULL){
           return 0;
        }
        int left = ans(root->left,maxx);
        int right = ans(root->right,maxx);
        int sum = root->val;
        if(left>0){
        
        sum += left;
        }
        if(right>0){

        sum += right;
        }
        maxx = max(maxx,sum);
        if(left >0 || right>0){
            return max(left,right) + root->val;
        }
        else return root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxx = INT_MIN;
        ans(root,maxx);
        return maxx;
    }
};
