class Solution {
  public:
  bool ans = false;
  
    string add(string a, string b){
        string res;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int n = a.length();
        int m = b.length();
        
        int len = max(n, m);
        int carry = 0;
        
        for(int i = 0; i < len; i++){
            int sum = 0;
            if(i < n) sum += (a[i] - '0');
            if(i < m) sum += (b[i] - '0');
            sum += carry;
            
            res.push_back('0' + (sum % 10));
        
            carry = (sum/10);
        }
        
        if(carry != 0) res.push_back('0' + carry);
        
        reverse(res.begin(), res.end());
        return res;
    }
  
    void rec(int i, vector<string>& store, string& s) {
        if(ans) return;  
        if(i == s.size()) {
            if(store.size() >= 3) ans = true;
            return;
        }
    
        for(int j = 1; j + i <= s.size(); j++) {
            string t = s.substr(i, j);
            if(t.size() > 1 && t[0] == '0') continue;  
            store.push_back(t);
    
            int sz = store.size();
            
            if(sz < 3 || add(store[sz - 2], store[sz - 3]) == store[sz - 1]) {
                rec(i + j, store, s);
            }
    
            store.pop_back();  
        }
    }

  
    bool isSumString(string &s) {
        ans = false;
        vector <string> store;
        rec(0, store, s);
        return ans;
    }
};