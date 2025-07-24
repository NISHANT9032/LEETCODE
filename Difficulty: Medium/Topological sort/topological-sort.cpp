class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        vector<int>indegree(V,0);
         for (auto& e : edges) 
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i = 0 ; i<V ; i++)
        { 
            if(indegree[i] == 0)
             q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        { 
            int node = q.front();
            q.pop();
            topo.push_back(node);
           for(auto it : adj[node])
           { 
             indegree[it]--;
             if(indegree[it] == 0) q.push(it);
           }
        }
        return topo;

    }
};