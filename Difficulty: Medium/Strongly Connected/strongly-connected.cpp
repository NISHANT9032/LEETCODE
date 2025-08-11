//Position this line where user code will be pasted.
class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) { 
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it])
                dfs(it, vis, adj, st);
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<int> &vis, vector<vector<int>> &adjT) { 
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it])
                dfs2(it, vis, adjT);
        } 
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;
        
        // Step 1: DFS to fill stack
        for (int i = 0; i < V; i++) { 
            if (!vis[i]) { 
                dfs(i, vis, adj, st);
            }
        }
        
        // Step 2: Reverse graph
        vector<vector<int>> adjT(V); // ✅ FIXED initialization
        for (int i = 0; i < V; i++) { 
            vis[i] = 0; // reset visited
            for (auto it : adj[i]) { 
                adjT[it].push_back(i); // reverse edge
            }
        }
        
        // Step 3: DFS on reversed graph
        int scc = 0;
        while (!st.empty()) { 
            int node = st.top();
            st.pop();
            if (!vis[node]) { 
                dfs2(node, vis, adjT);
                scc++; // ✅ increment SCC count
            }
        }
        
        return scc;
    }
};
