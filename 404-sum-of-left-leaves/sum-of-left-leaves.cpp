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
    void solve(TreeNode* root,int &ans,bool isleft){
        if(root->left==NULL && root->right==NULL){
            if(isleft) ans+=root->val;
            return;
        } 

        if(root->left) solve(root->left,ans,true);
        if(root->right) solve(root->right,ans,false);
    }


    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        bool isleft=false;
        solve(root,ans,isleft);
        return ans;
        
    }
};