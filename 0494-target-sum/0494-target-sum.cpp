class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0, n = nums.size();
        for (int i = 0; i < n; ++i) total += nums[i];
        if ((total - target) < 0 || (total - target) & 1) return 0;
        int sum = (total - target) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int j = sum; j >= num; --j) dp[j] += dp[j - num];
        }
        return dp[sum];
    }
};
