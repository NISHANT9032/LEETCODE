class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256 , -1);
        int l = 0 , result= 0 ;
        for(int r = 0 ; r < s.size() ; r++)
        { 
            if(mpp[s[r]] >=l) l = mpp[s[r]] +1;

            mpp[s[r]] = r;
            result = max(result , r-l+1);
        }
        return result;
    }
    
};