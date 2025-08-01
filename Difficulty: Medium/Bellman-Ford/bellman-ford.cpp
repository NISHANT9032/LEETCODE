// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        for(int i =0 ; i< V-1 ; i++)
        { 
            for(auto it : edges )
            {
                int u = it[0] ,  v = it[1] , wt = it[2];
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                  dist[v] = dist[u] + wt;
                
            }
        }
        
        for(auto it : edges )
            {
                int u = it[0] ,  v = it[1] , wt = it[2];
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                   return {-1};
                
            }
        for (int i = 0; i < V; ++i) {
           if (dist[i] == INT_MAX) {
             dist[i] = 100000000;
            }
         }
        
        return dist;
    }
};
