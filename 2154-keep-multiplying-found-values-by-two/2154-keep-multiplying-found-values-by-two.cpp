class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int bits = 0;
        for (auto& n : nums) {
            if (n % original != 0) continue;
            n = n / original ;
            if ((n & (n - 1)) == 0)
                bits |= n;
        }
        int d = bits + 1;
        return original * (d & -d);
    }
};