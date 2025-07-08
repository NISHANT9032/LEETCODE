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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int preStart = 0, preEnd = preorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;
        map<int ,int>inMap;
        for(int i=inStart;i<=inEnd;i++)
        {
            inMap[inorder[i]] =i;
        }
        TreeNode* root=build(preorder,preStart,preEnd,inorder,inStart,inEnd,inMap);
        return root;   
    }
    TreeNode* build(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int> & inMap){
     if(preStart>preEnd || inStart>inEnd)  return NULL;
     TreeNode* root =new TreeNode(preorder[preStart]);
     int inRoot=inMap[root->val];
     int numsLeft=inRoot-inStart;

     root->left=build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);  
     root->right=build(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
     return root;   


    }
};