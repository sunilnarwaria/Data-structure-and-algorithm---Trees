 vector<int> rightSideView(TreeNode* root) {
        
       queue<TreeNode*>mQ;
        vector<int> ret;
        if(!root)return ret;
        mQ.push(root);
        while(!mQ.empty()){
            ret.push_back(mQ.front()->val);
            for(int i=mQ.size();i>0;i--){
                TreeNode *tn=mQ.front();
                mQ.pop();
                if(tn->right)mQ.push(tn->right);
                if(tn->left)mQ.push(tn->left);
            }
        }
        return ret;
    }
