class Solution {
  private:
    unordered_map<int, string> decimalString;
  
    string convertDecimalToString(int num) {
        string str;
        
        if(num == 0) {
            return "0";
        }
        
        while(num > 0) {
            str += '0' + num % 10;
            num = num / 10;
        }
        
        reverse(str.begin(), str.end());
        
        return str;
    } 
    
    struct comp {
        unordered_map<int, string> &decimalString;
        comp(unordered_map<int, string> &ds) : decimalString(ds) {}

        bool operator()(int x, int y) {
            string a = decimalString[x];
            string b = decimalString[y];
            
            return (a+b) > (b+a);
        }  
    };
    
  public:
    string findLargest(vector<int> &arr) {
        bool allZeros = true;
        for(auto &x: arr) {
            if(x != 0) {
                allZeros = false;
            }
            decimalString[x] = convertDecimalToString(x);
        }
        
        if(allZeros) {
            return "0";
        }
        
        sort(arr.begin(), arr.end(), comp(decimalString));
        
        string res;
        for(auto &x: arr) {
            res += to_string(x);
        }
        return res;
    }
};