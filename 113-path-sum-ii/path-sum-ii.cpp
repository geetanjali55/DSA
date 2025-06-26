class Solution {
public:
    void solve(TreeNode* root,vector<vector<int>>&ans,vector<int>path,int targetSum){
        if(!root) return;

        path.push_back(root->val);
        targetSum-=root->val;

        // Reached Leaf Node
        if(!root->left && !root->right){
            if(targetSum==0){
                ans.push_back(path);
            }
            return;
        }

        solve(root->left,ans,path,targetSum);
        solve(root->right,ans,path,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;

        solve(root,ans,path,targetSum);
        return ans;
    }
};