class Solution {
  public:
    using info = tuple<int, int, int>;
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        const int n = matrix.size();
        priority_queue<info, vector<info>, greater<info>> pq;
        int val, x, y;
        for (int i = 0; i < n; i++) {
            pq.push(make_tuple(matrix[i][0], i, 0));
        }
        while (k > 1) {
            tie(val, x, y) = pq.top();
            pq.pop();
            
            if(y + 1 < n) pq.push(make_tuple(matrix[x][y + 1], x, y + 1));
            k--;
        }
        return get<0>(pq.top());
    }
};