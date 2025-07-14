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
 class NodeValue{
    public:
    int maxNode, minNode ,maxSum;
    NodeValue(int maxNode,int minNode, int maxSum){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
    }
 };
class Solution {

public:
      int MAX_SUM = INT_MIN;
     NodeValue largestBSTSubtreeSum(TreeNode* root){
        if(!root){
            return NodeValue(INT_MIN,INT_MAX,0);
        }
        auto left = largestBSTSubtreeSum(root->left);
        auto  right = largestBSTSubtreeSum(root->right);
        
        if(left.maxNode < root->val && root->val< right.minNode ){
           //It is an BST
             MAX_SUM = max(root->val + left.maxSum + right.maxSum,MAX_SUM);     
           return NodeValue(max(root->val , right.maxNode) , min(root->val, left.minNode),root->val + left.maxSum + right.maxSum);
        }
        else{
           return NodeValue(INT_MAX , INT_MIN ,max(left.maxSum , right.maxSum));
        }

     }
    int maxSumBST(TreeNode* root) {
     largestBSTSubtreeSum(root);
     return (MAX_SUM<0)?0:MAX_SUM;
    }
};