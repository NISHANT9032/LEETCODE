class Solution {
  public:
    string caseSort(string& s) {
        // code here
         string res = "";
        priority_queue<int, vector<int>, greater<int>> minHeap1;
        priority_queue<int, vector<int>, greater<int>> minHeap2;
        
        for(int i=0 ; i<s.length() ; i++)
        {
            if(isupper(s[i]))
                minHeap1.push(int(s[i]));
            else
                minHeap2.push(int(s[i]));
        }
        
        for(int i=0 ; i<s.length() ; i++)
        {
            if(isupper(s[i]))
            {   res+=minHeap1.top();
                minHeap1.pop();
            }
            else
            {   
                res+=minHeap2.top();
                minHeap2.pop();
            }
        }
        
        return res;
    }
};