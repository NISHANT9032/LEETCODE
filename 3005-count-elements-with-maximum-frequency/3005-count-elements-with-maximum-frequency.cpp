class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       map<int , int > m ;
       int c = 0 , maxi = 0 ;

       for(int i = 0 ; i< nums.size() ; i++)
       { 
          m[nums[i]]++;

         if(m[nums[i]] > maxi) 
         {
            maxi = m[nums[i]];
            c = 0;
         }

         if(m[nums[i]] == maxi)
         { 
            c++;
         }

       }

       return c*maxi; 
    }
};