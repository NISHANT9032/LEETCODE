class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int can1 = -1, can2 = -1, cnt1=0, cnt2=0;
        vector<int>result;
        for(auto num : nums)
        { 
            if(num == can1) cnt1++;
            else if(num == can2) cnt2++;
            else if(cnt1 == 0)
            {
                can1 = num ;
                cnt1++;
            }
            else if(cnt2 == 0)
            {
                can2 = num ;
                cnt2++;
            }
            else{ 
                cnt1--;
                cnt2--;
            }
        }

        cnt1=cnt2=0;
        for(auto num : nums)
        { 
            if(num == can1) cnt1++;
            if(num == can2) cnt2++;
        }
        if(cnt1 > n/3) result.push_back(can1);
        if(cnt2 > n/3) result.push_back(can2);

         if(can1 == can2) return{can1};
         else{ return result;}
    }
};