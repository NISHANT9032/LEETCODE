class Solution {
public:
    string largestOddNumber(string num) {
        if(num.back() % 2 == 1) return num;
        int n = num.length() -1;
        while(n >= 0)
        { 
            int i = num[n];
            if(i % 2 == 1) return num.substr(0,n+1);
            n--;
        }
        return "";
    }
};