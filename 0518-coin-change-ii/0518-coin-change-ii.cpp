class Solution {
public:
    int change(int amount, vector<int>& coins) {
         using u128 = unsigned __int128;
        int n = coins.size();
        vector<vector<u128>> dp(n, vector<u128>(amount+1, 0));
        for (int T = 0; T <= amount; T++) {
            dp[0][T] = (T % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int T = 0; T <= amount; T++) {
                u128 notTake = dp[ind-1][T];
                u128 take = 0;
                if (coins[ind] <= T)
                    take = dp[ind][T - coins[ind]];
                dp[ind][T] = take + notTake;
            }
        }
        return (int)dp[n-1][amount];
    }
};

