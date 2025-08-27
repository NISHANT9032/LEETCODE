class Solution {
  public:
    int longestCommonSubstr(string& text1, string& text2) {
        // your code here
         int n = text1.size();
        int m = text2.size();
        vector<int>prev(m+1 ,0) , curr(m+1 , 0);
        for(int j =0 ; j<=m ; j++) prev[j] = 0;
        int ans =0;
        for(int i=1; i<=n ; i++ ){ 
            for(int j = 1 ; j<=m ; j++){
              if(text1[i-1] == text2[j-1]) 
              {
                  curr[j] = 1+ prev[j-1];
                  ans = max(ans, curr[j]);
              }
              else curr[j] = 0;
            }
           prev = curr;
        }
        return ans;
    }
};