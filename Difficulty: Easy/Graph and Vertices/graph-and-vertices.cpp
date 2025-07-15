// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        // your code here
        if(n <= 2 ) return n;
        int edge = n*(n-1)/2;
        
        return pow(2,edge);
        
    }
};