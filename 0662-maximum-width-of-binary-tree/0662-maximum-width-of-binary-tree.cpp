class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root==NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty())
        {
            long long size=q.size();
            int min=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                long long curr=q.front().second-min;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)
                {
                    first=curr;
                }
                if(i==size-1)
                {
                    last=curr;
                }
                if(node->left)
                {
                    q.push({node->left,curr*2+1});  
                }
                if(node->right)
                    {
                        q.push({node->right,curr*2+2});
                    }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};