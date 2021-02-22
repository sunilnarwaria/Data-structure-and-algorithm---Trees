///Interviewbit
int Solution::hasPathSum(TreeNode* A, int B) {
    if (A == NULL)
        return 0;
    B -= A->val;
    if (A->left == NULL && A->right == NULL && B == 0)
        return 1;
    int left = hasPathSum(A->left, B);
    int right = hasPathSum(A->right, B);
    
    return left || right;
}
