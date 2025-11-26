class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int prf = 1 ,  suff=1;
        for(int i = 0; i<n ; i++)
        {
          if(prf == 0) prf = 1;
          if(suff == 0) prf= 1;
          prf *=nums[i];
          suff *= nums[n-i-1];
          ans = max(ans , max(prf , suff));
        }
        return ans;
    }
};