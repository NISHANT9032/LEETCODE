class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int n = arr.size();
        // Initialize binary search bounds
        int low = 1; // Smallest possible divisor
        int high = *max_element(arr.begin(), arr.end()); // Largest possible divisor needed
        int ans = 1e9; // Initialize answer with a large value

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid overflow, find mid
            int cnt = 0; // Sum of ceilings
            
            // Calculate the sum of ceilings for current 'mid' (divisor)
            for (int x : arr) {
                cnt += ((x + mid - 1) / mid); // Equivalent to ceil(x / mid)
            }
            
            // If sum <= k, it's a valid candidate, try for a smaller divisor
            if (cnt <= k) {
                ans = mid; // Update answer
                high = mid - 1; // Search left half
            } else {
                low = mid + 1; // Search right half
            }
        }
        
        return ans; // Smallest valid divisor found
    }
};