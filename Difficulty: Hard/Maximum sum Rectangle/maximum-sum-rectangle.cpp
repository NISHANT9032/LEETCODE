class Solution {
    int kadane(vector<int>&vec){
        int n=vec.size();
        int maxi=vec[0];
        int local_sum=vec[0];
        for(int i=1;i<n;i++){
            if(vec[i]+local_sum>=vec[i]){
                local_sum=vec[i]+local_sum;
            }
            else{
                local_sum=vec[i];
            }
            maxi=max(maxi,local_sum);
        }
        return maxi;
    }
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int r=mat.size();
        int c=mat[0].size();
        int res=-3e5-7;
        for(int i=0;i<c;i++){
            vector<int>temp(r,0);
            for(int j=i;j<c;j++){
                for(int k=0;k<r;k++){
                    temp[k]+=mat[k][j];
                }
                res=max(res,kadane(temp));
            }
        }
        return res;
    }
};