class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> sum;
        int r = mat.size();
        int c = mat[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                sum[i + j].push_back(mat[i][j]);
            }
        }

        vector<pair<int, vector<int>>> v;

        for (auto it : sum) {
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end());

        vector<int> v1;

        for (auto it : v) {
            if (it.first % 2 == 0) {
                reverse(it.second.begin(), it.second.end());
            }
            v1.insert(v1.end(), it.second.begin(), it.second.end());
        }

        return v1;
    }
};