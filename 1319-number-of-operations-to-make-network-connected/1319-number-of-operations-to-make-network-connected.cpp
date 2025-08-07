class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findupar(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findupar(parent[u]); // Path compression
    }

    void unionbyrank(int u, int v) {
        int upu = findupar(u);
        int upv = findupar(v);
        if (upu == upv)
            return;
        if (rank[upu] > rank[upv]) {
            parent[upv] = upu;
        } else if (rank[upu] < rank[upv]) {
            parent[upu] = upv;
        } else {
            parent[upu] = upv;
            rank[upv]++; // Fix: increment rank of new root
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        if(connections.size() < n-1) return -1;
        for(auto i : connections)
          ds.unionbyrank(i[1],i[0]);
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.findupar(i)==i){
                count++;
            }
        }
        return count-1;
    }

};