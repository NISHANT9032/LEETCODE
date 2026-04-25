class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector<int> mpp(256,-1);
      int l = 0 , res = 0 ;
      for(int r = 0 ; r < s.size() ; r++)
      {
         if(mpp[s[r]] >= l) l=mpp[s[r]] + 1;
         mpp[s[r]] = r;
         res = max(res, r-l+1);
      }
        return res;
    }
};