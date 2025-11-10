class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
       int sumx = (n*(n+1))/2;
       return sumx-accumulate(nums.begin(),nums.end(),0); 
    }
};