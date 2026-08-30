class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = min_element(nums.begin(), nums.end()) -  nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(mini, maxi);
        int right = max(mini, maxi);

        int option1 = right + 1;
        int option2 = n - left;
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};