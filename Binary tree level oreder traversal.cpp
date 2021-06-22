
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> v2;
        if(root==NULL) return vector<vector<int>>();
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int count=q.size();
             vector<int> v;
            for(int i=0;i<count;i++){
                TreeNode *curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            v2.push_back(v);
        }
        return v2;
        
    }
};
