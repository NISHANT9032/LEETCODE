class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(256, 0);
        vector<int> indexT(256, 0);
        
        int len = s.length();
        if(len != t.length()) return false;
        
        for(int i = 0; i < len; i++) {
            
            if(indexS[s[i]] != indexT[t[i]]) return false;
            
            indexS[s[i]] = i + 1;
            indexT[t[i]] = i + 1;
        }
        
        return true;
        
    }
};