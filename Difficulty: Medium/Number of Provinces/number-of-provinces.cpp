// User function Template for C++

class Solution {
  public:
  
    void dfs(int node , vector<vector<int>> &adj,vector<bool> &visited)
    {
        visited[node] = true;
         for (int i = 0; i < adj.size(); ++i) {
            if (adj[node][i] == 1 && !visited[i])
               dfs(i, adj, visited);
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool>visited(V,false);
        int provinces = 0;
        for(int i=0 ; i<V ; ++i )
        {
            if(!visited[i])
            {
                dfs(i , adj , visited);
                provinces++;
            }
        }
        return provinces;
    }
};