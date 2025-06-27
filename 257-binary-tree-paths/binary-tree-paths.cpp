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
    void func(TreeNode* root,string &s, vector<string> &v){
        if(!root) return;
        int len=s.length(); //len of the string before appending the next iteration
        if(!s.empty()) s+="->";
        s+=to_string(root->val);
        if(!root->left && !root->right){
            v.push_back(s);
            s.erase(len); //remove
            return;
        } // check if leaf node
        func(root->left, s, v);
        func(root->right,s,v);
        s.erase(len); // backtracking
        return ;
    }
/*
    s.erase()                // Erases whole string
    s.erase(idx)             // Erases all characters after idx
    s.erase(idx, k)          // Erases k characters after idx
    s.erase(itr)             // Erases character at itr
    s.erase(first, last)     // Erases character in range [first, last)
*/

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(!root) return v;
        string s ="";
        func(root,s, v);
        return v;
    }
};