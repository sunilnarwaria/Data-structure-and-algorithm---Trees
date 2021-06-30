lic:
    TreeNode* Bst(vector<int>& nums,int l,int h){
        if(l>=h) return NULL;
        int mid = (l+h)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = Bst(nums,l,mid);
        root->right = Bst(nums,mid+1,h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return Bst(nums,0,n);
    }
