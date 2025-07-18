class Solution {
  public:
  bool dfs(int node,int parent ,vector<int>&vis, vector<vector<int>>& adj)
  { 
      vis[node] = 1;
      for(auto it : adj[node])
      { 
          if(!vis[it])
            { 
                if(dfs(it,node,vis,adj) == true)
                 return true;
            }
          else if(it != parent ) return true;
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
           vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
          vector<int> vis(V, 0);
        for (int i =0 ; i<V ; i++ )
        { 
            if(!vis[i])
              if(dfs(i,-1,vis,adj) == true)  return true;
             
        }   
        return false;
        
    }
};