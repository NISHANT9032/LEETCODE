class Solution {
public:
 int count(vector<int>&nums , int k )
 {
    int left = 0 , result =0;
    for(int r = 0 ; r<nums.size() ; r++)
    {
        if(nums[r]%2 != 0)
          k--;
        
        while(k<0)
        {
            if(nums[left] % 2 != 0)
             k++;
          left++; 
        }
        result += (r-left+1);
    } 
    return result;

 }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums,k) - count(nums , k-1); 
    }
};