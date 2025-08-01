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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root,maxSum);
        return maxSum;
        
    }
    int maxGain(TreeNode* root , int& maxSum)
    { 
        if(!root) return 0;
        int left = max(0,maxGain(root->left,maxSum));
        int right = max(0,maxGain(root->right,maxSum));
        
        maxSum= max(maxSum,left+root->val+right);
        return root->val+max(left,right);
    }
};