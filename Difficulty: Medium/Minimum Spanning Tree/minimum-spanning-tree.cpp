class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
       vector<pair<int, int>> adj[V]; 
       for (auto &edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); 
      }

        priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int>vis(V,0);
        
        pq.push({0,0});
        int sum = 0 ;
        while(!pq.empty())
        { 
            auto it = pq.top();
             pq.pop();
            int node = it.second;
            int edW = it.first;
            
            if(vis[node] == 1) continue ;
            vis[node] = 1;
            sum = sum + edW;
            for(auto [adjNode, edWT] : adj[node])
            { 
             
                if(!vis[adjNode])
                { 
                    pq.push({edWT , adjNode});
                }
            }
        }
        
        return sum ;
        
    }
};