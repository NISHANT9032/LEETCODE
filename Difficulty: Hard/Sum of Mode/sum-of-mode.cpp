class Solution {
  public:
    void add_val(vector<int>& arr, int i, unordered_map<int,int>& num_count, map<int,set<int>> &rank)
    {
        num_count[arr[i]]++;
        int cur_val = num_count[arr[i]];
        
        if(cur_val!=1)
        {
            rank[cur_val-1].erase(arr[i]);
            if(rank[cur_val-1].empty())
            rank.erase(cur_val-1);
        }
        rank[cur_val].insert(arr[i]);
    }
    
    void del_val(vector<int>& arr, int i, unordered_map<int,int>& num_count, map<int,set<int>> &rank)
    {
        num_count[arr[i-1]]--;
        int cur_val = num_count[arr[i-1]];
        if(cur_val!=0)
        rank[cur_val].insert(arr[i-1]);
        rank[cur_val+1].erase(arr[i-1]);
        if(rank[cur_val+1].empty())
        rank.erase(cur_val+1);
    }
  
    int sumOfModes(vector<int>& arr, int k) {
        int res = 0;
        unordered_map<int,int> num_count;
        map<int,set<int>> rank;
        
        for(int i=0;i<k;i++)
        add_val(arr, i, num_count, rank);
        
        // This is the way to get highest rank element, 
        // and if 2 elements are having same rank, 
        // the ordered set returns lowerst value
        res += ( *( ( (*(rank.rbegin())).second ).begin()) );
        
        for(int i=1;i<=(arr.size()-k);i++)
        {
            del_val(arr, i, num_count, rank);
            add_val(arr, i+k-1, num_count, rank);
            res += ( *( ( (*(rank.rbegin())).second ).begin()) );
        }
        
        return res;
    }
};