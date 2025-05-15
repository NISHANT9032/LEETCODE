class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
         vector<string> res = {w[0]};
        for (int i = 1; i < g.size(); ++i) {
            if (g[i] != g[i - 1]) res.push_back(w[i]);
        }
        return res;
    }
};