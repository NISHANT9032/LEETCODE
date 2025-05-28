class Solution {
    bool isPalindrome(vector<vector<int>>& dp, string& s, int start, int end) {
        if(start >= end) // Edge case: If no letters exists then string is palindrome
            return true;
        
        if(s[start] != s[end]) // Edge case: If both letters don't match then string can't be palindrome
            return false;

        if(dp[start][end] != -1)
            return dp[start][end];
        
        return dp[start][end] = isPalindrome(dp, s, start + 1, end - 1);
    }

public:
    // Method to find the longset palindromic substring, using recursion with memoization - O(N^2) & O(N^2)
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int maxLength = 0;
        int start, end;

        for(int i = 0; i < n; ++i) // Find length of the longest palindromic substring
            for(int j = i; j < n; ++j)
                if(isPalindrome(dp, s, i, j) && j-i+1 > maxLength) 
                    maxLength = j-i+1, start = i, end = j;

        // Get the longest palindromic substring using its start and end index and then return it
        return s.substr(start, end-start+1);
    }
};
// Note: Without Memoization DP The Time Complexity Is O(N^3).