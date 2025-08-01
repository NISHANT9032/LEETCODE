class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V = adj.size();
        vector<int> dist(V,-1);
        queue<int>q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty())
        { 
            int u = q.front();
            q.pop();
            
            for(auto v : adj[u])
            { 
                if(dist[v] == -1)
                { 
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
};