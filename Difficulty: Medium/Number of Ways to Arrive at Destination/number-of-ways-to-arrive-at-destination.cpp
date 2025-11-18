class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int src = 0, dest = V - 1;

       
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int mini = dist[dest];
        int ans = 0;

      
    
       auto dfs = [&](auto&& dfs,int u)->void {
            if (u == dest) {
                ans++;
                return;
            }
            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w == dist[v]) {  
                    dfs(dfs,v);  
                }
            }
        };

        dfs(dfs,src);
        return ans;
    }
};