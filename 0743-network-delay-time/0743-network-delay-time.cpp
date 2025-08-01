class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto& it : times)
        { 
            adj[it[0]].push_back({it[1],it[2]});
        }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
       vector<int>dist(n+1 , INT_MAX);
       dist[k] = 0;
       pq.push({0,k});
       while(!pq.empty())
       { 
         auto[time, u] = pq.top();
         pq.pop();
         for(auto [v,w] : adj[u])
         { 
            if (dist[v] > time + w) {
                    dist[v] = time + w;
                    pq.push({dist[v], v});
                }
         }
       }
       int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};