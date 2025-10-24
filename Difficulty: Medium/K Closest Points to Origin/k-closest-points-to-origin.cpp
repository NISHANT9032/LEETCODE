class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
    priority_queue<pair<double, int>, vector<pair<double, int>> , greater<pair<double, int>>> pq;
    for(int i=0; i<points.size(); i++){
        int x= points[i][0];
        int y= points[i][1];
        double getAns= pow(x, 2) + pow(y, 2);
        double ans= sqrt(getAns);
        pq.push(make_pair(ans, i));
    }
    while(k--){
        auto i= pq.top();
        pq.pop();
        ans.push_back(points[i.second]);
    }
    return ans;
    
    }
};