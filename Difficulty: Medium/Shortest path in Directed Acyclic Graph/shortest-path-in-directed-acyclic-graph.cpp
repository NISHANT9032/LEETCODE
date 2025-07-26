// User function Template for C++
class Solution {
  public:
    void topo(int node,vector<pair<int,int>> adj[],vector<bool>&visit,stack<int>&s){
        visit[node] = true;
        for(int i = 0;i<adj[node].size();i++){
            if(!visit[adj[node][i].first]){
                topo(adj[node][i].first,adj,visit,s);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[V];
        for(auto& ch : edges){
            int u = ch[0], v = ch[1], wt = ch[2];
            adj[u].push_back({v,wt});
        }
        vector<bool>visit(V,false);
        stack<int>s;
        topo(0,adj,visit,s);
        
        vector<int>ans(V,INT_MAX);
        ans[0] = 0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            for(int i = 0;i<adj[top].size();i++){
                ans[adj[top][i].first] = min(ans[adj[top][i].first],ans[top]+adj[top][i].second);
            }
        }
        for(auto& ch : ans){
            if(ch==INT_MAX) ch = -1;
        }
        return ans;
    }
};