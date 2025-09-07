class Solution {
public:

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;

        int n1 = s1.size();
        int n2 = s2.size();
        //vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        vector<int>dp(n2+1, 0);
        for(int i=1; i<=n1; i++){
            vector<int>curr(n2+1, 0);
            for(int j=1; j<=n2; j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = 1+dp[j-1];
                }
                else{
                    curr[j] =  max(dp[j], curr[j-1]);
                }
            }
            dp = curr;
        }
        return dp[n2];
    }
};