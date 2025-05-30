class Solution {
public:
    int myAtoi(string s) {
       int size = s.size();
       int ans = 0;
       int pos = 1;
       int i = 0;
       while(i<size && s[i] == ' ') i++;
       if(i<size && (s[i] == '-' || s[i] == '+'))
       { 
        
        if(s[i] == '-')  pos = -1;
         i++; 
       }
        
        while(i<size && (s[i]>='0' && s[i]<='9')){
            if(ans > (INT_MAX-(s[i]-'0'))/10){
                return pos==1 ? INT_MAX : INT_MIN;
            }
            ans = (ans*10) + (s[i]-'0');    
            i++;
        }
        return ans*pos;

    }
};