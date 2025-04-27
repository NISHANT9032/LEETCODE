class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); //size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ nums[i];
    }
    return ans;
    }
};