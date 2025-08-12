class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int prev = 1 , curr = 1;
        //dp[0] = dp[1] = 1;
        for(int i=2 ; i<=n ; i++)
        {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
            //dp[i] = dp[i-1] + dp[i-2];
        }
        return curr;
    }
};