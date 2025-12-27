class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
          vector<int> arr;
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr.push_back(mat[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};
