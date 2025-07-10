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
      int count = 0;
    void calcSmallest(TreeNode* root, int k, int& ans){
        if(root==nullptr){
            return ;
        }
        calcSmallest(root->left,k,ans);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        calcSmallest(root->right,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        calcSmallest(root,k,ans);
        return ans;
    }
};