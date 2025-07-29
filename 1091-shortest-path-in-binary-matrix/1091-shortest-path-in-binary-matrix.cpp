class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<pair<int, int>> directions = 
        {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1;
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            int d = grid[i][j];

            if (i == n - 1 && j == n - 1) return d;

            for (auto [dx, dy] : directions) {
                int ni = i + dx, nj = j + dy;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                    grid[ni][nj] = d + 1;
                    q.push({ni, nj});
                }
            }
        }

        return -1;
    }
};