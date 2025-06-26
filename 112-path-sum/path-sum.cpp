class Solution {
    bool path(TreeNode* root, int curr, int target){
        if(!root) return 0;
        curr += root->val;
        if(!root->left && !root->right && curr == target) return 1;
        return path(root->left, curr, target) || path(root->right, curr, target);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return path(root, 0, targetSum);
    }
};