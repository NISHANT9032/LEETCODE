class Solution {
public:
    vector<int>topoSortBFS(int V, vector<int> adj[])
    { 
        vector<int> topo;
        vector<int> indegree(V,0);
        queue<int>q;
        for(int i =0 ; i< V ; i++)
        { 
            for(auto it : adj[i])
            { 
                indegree[it]++;
            }
        }
        for(int i =0 ; i<V ; i++)
        { 
            if(indegree[i] == 0) q.push(i);
        }
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i =0 ; i<prerequisites.size();i++)
        { 
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> topo = topoSortBFS(numCourses , adj);
        if(topo.size() == numCourses) return topo;
        return {};
    }
};