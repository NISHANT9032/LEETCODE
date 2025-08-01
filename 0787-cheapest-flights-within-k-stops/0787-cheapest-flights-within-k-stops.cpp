class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     vector<pair<int,int>> adj[n];
     for(auto it : flights)
     { 
        adj[it[0]].push_back({it[1],it[2]});
     }
     queue<pair<int,pair<int,int>>>q;
     q.push({0,{src,0}});
     vector<int>dist(n,INT_MAX);
     dist[src] = 0;
     while(!q.empty()) 
     { 
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node  = it.second.first;
        int cost  = it.second.second;

        if(stops > k ) continue; 
        for(auto itr : adj[node])
        { 
            int adjNode = itr.first;
            int edw = itr.second;
            if(cost + edw < dist[adjNode] && stops <= k)
            {
                dist[adjNode] =  cost + edw ;
                q.push({stops+1,{adjNode,cost + edw}});
            }
        }
     }
     if(dist[dst] == INT_MAX) return -1;
     return dist[dst];
    }
};