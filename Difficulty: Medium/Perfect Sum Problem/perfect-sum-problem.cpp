class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<int>dp(target+1,0);
        dp[0] = 1; 
        for(auto num : arr){
            for(int j = target; j >= num; j--){
                dp[j] += dp[j-num];
            }
        }
        return dp[target];
    }
};