class Solution {
public:
    bool isValid(string s) {
         if (s.size() % 2 != 0) return false;
        stack<char>stack;
        for(char c : s){
            if(c == '(' || c=='[' || c=='{')
            {
                stack.push(c);
            }else
            {
                if(stack.empty())   return false;
                char top=stack.top();
                stack.pop();
                //stack.pop();
                if((c == ')' && top != '(') || 
                    (c == '}' && top != '{') || 
                    (c == ']' && top != '[')){
                        return false;
                        //stack.pop();
                    }
            }
        }
        return stack.empty();
    }
};