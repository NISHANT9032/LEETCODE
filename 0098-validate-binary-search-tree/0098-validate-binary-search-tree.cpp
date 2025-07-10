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
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN , LONG_MAX);
    }
    bool isBST(TreeNode* node , long minVal , long maxVal)
    { 
        if(!node) return true;
        if(node->val <= minVal || node->val >= maxVal )
           return false;
        return isBST(node->left, minVal, node->val) &&
               isBST(node->right, node->val, maxVal);
        
    }
};