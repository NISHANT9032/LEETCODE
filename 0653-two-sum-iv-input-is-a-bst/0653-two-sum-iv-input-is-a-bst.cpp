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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>s;
        return solve(root , k , s);
    }
    bool solve(TreeNode* root , int k , unordered_set<int> & s)
    { 
        if(!root) return false;
        if(s.count(k-root->val)) return true;
        s.insert(root->val);
        return solve(root->left,k,s) || solve(root->right, k, s);

    }
};