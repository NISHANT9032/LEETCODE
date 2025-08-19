class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        long total = 0;
        for (int x : nums) total += x;

        // split nums into two halves
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // store subset sums grouped by size
        vector<vector<long>> leftSums(n+1), rightSums(n+1);

        // generate all subset sums for left half
        for (int mask = 0; mask < (1 << n); mask++) {
            long sum = 0;
            int bits = __builtin_popcount(mask);
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) sum += left[i];
            }
            leftSums[bits].push_back(sum);
        }

        // generate all subset sums for right half
        for (int mask = 0; mask < (1 << n); mask++) {
            long sum = 0;
            int bits = __builtin_popcount(mask);
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) sum += right[i];
            }
            rightSums[bits].push_back(sum);
        }

        // sort right half sums for binary search
        for (int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        long ans = LLONG_MAX;

        // try all splits of elements between halves
        for (int k = 0; k <= n; k++) {
            for (long s1 : leftSums[k]) {
                long need = total/2 - s1;
                auto& arr = rightSums[n-k];

                // binary search closest sum in right side
                auto it = lower_bound(arr.begin(), arr.end(), need);
                if (it != arr.end()) {
                    long sumChosen = s1 + *it;
                    long other = total - sumChosen;
                    ans = min(ans, abs(other - sumChosen));
                }
                if (it != arr.begin()) {
                    --it;
                    long sumChosen = s1 + *it;
                    long other = total - sumChosen;
                    ans = min(ans, abs(other - sumChosen));
                }
            }
        }
        return (int)ans;
    }
};
