class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0 || (x > 0 && x % 10 == 0)) {
            return false;
        }

        int y = 0; // Reversed half of the number

        // Keep reversing digits until y >= x
        // This means we've reversed half the number
        while (y < x) {
            y = y * 10 + x % 10; // Add the last digit of x to y
            x /= 10;             // Remove the last digit from x
        }

        // If the number has even digits, x == y
        // If it has odd digits, the middle digit doesn't matter: x == y / 10
        return x == y || x == y / 10;
        
    }
};