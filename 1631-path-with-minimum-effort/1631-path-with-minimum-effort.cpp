class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        effort[0][0]=0;

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({0,0,0});

        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};

        while(!pq.empty()){
            auto [diff,x,y]=pq.top();
            pq.pop();

            if(x==n-1 && y==m-1){
                return diff;
            }

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int newEffort=max(diff,abs(heights[x][y]-heights[nx][ny]));
                    if(newEffort<effort[nx][ny]){
                        effort[nx][ny]=newEffort;
                        pq.push({newEffort,nx,ny});
                    }
                }
            }
        }
        return 0;
    }
};