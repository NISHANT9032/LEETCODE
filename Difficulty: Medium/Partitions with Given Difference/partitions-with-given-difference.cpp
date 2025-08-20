class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if ((sum + d) % 2 != 0) return 0;

    int tar = (sum + d) / 2;
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = tar; j >= arr[i]; j--) {
            dp[j] += dp[j - arr[i]];
        }
    }
    return dp[tar];
   }

};