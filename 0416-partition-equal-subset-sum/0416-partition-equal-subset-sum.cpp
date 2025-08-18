class Solution {
private:
         bool solveSO(int index,vector<int>& nums,int n,int total)
    {
        vector<int> curr(total+1,0);
        vector<int> next(total+1,0);
        curr[0]=1;
        next[0]=1;



        for(int index=n-1;index>=0;index--)
        {
            for(int target=0;target<=total/2;target++)
            {
                    bool include=0;
                    if(target-nums[index]>=0)
                         include=next[target-nums[index]];
                    bool exclude=next[target-0];

                    curr[target]=include or exclude;
            }
            next=curr;
        }
        return next[total/2];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;

        for(int i=0;i<n;i++)
        {
            totalsum+=nums[i];
        }
        if(totalsum%2!=0){
            return 0;
        }
        
        int target=totalsum/2;

        return solveSO(0,nums,n,totalsum);
    }
};