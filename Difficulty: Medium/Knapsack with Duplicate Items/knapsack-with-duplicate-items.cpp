// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<int> prev(capacity+1 , 0);
        for(int w = 0 ; w<=capacity ; w++)
        { 
            prev[w] = ((int) (w / wt[0])) * val[0];
        }
        for(int ind = 1; ind <n ; ind++){
            for(int w =0 ; w<=capacity ; w++){
                int notTake = 0 + prev[w];
                int take = 0;
                if(wt[ind] <= w)
                 take = val[ind] + prev[w - wt[ind]];
                prev[w] = max(take , notTake);
            }
        }
        return prev[capacity];
    }
};