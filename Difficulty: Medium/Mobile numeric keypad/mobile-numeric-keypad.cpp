class Solution {
  public:
    int rec(int len,int prev_digit,int n,vector<vector<int>>&dp,vector<vector<int>>&adj){
        if(len==n){
            return 1;
        }
        if(prev_digit!=-1 && dp[len][prev_digit]!=-1){
            return dp[len][prev_digit];
        }
        int ans=0;
        if(prev_digit==-1){
            for(int d=0;d<=9;d++){
                ans+=rec(1,d,n,dp,adj);
            }
        }
        else{
            for(auto d:adj[prev_digit]){
                ans+=rec(len+1,d,n,dp,adj);
            }   
        }
        if(prev_digit!=-1){
            dp[len][prev_digit]=ans;
        }
        return ans;
    }
    int getCount(int n) {
        // code here
        vector<vector<int>>adj(10);
        adj[0]={0,8};
        adj[1]={1,2,4};
        adj[2]={1,2,3,5};
        adj[3]={2,3,6};
        adj[4]={1,4,5,7};
        adj[5]={2,4,5,6,8};
        adj[6]={3,5,6,9};
        adj[7]={4,7,8};
        adj[8]={0,5,7,8,9};
        adj[9]={6,8,9};
        
        vector<vector<int>>dp(n,vector<int>(10,-1));
        return rec(0,-1,n,dp,adj);
    }
};