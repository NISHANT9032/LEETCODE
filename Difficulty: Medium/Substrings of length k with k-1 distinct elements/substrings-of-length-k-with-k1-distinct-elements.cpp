class Solution {
  public:
    int substrCount(string &s, int k) 
    {
        unordered_map<char,int> mp;
        int ans = 0;
        int zero_counter = 0;
        if(k > s.size())
            return 0;
        int start = 0;
        int end = 0;
        for(int i = 0; i < k; i++)
        {
            mp[s[i]]++;
            end++;
        }
        if(mp.size() == k-1)
            ans++;
        if(k == s.size())
            return ans;
        
        for(int i = end; i < s.size(); i++)
        {
            if(mp[s[start]])
                mp[s[start]]--;
            mp[s[end]]++;
            if(mp[s[start]] == 0)
            {
                auto itr = mp.find(s[start]);
                mp.erase(itr);
            }
            if( mp.size() == k-1)
                ans++;
                
            start++;
            end++;
        }
        return ans;
        // code here
        
    }
};