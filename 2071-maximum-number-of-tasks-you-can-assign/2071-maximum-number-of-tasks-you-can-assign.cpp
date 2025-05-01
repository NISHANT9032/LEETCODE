class Solution {
public:
    bool canFinish(int mid, const vector<int>& tasks, const vector<int>& workers, int pills, int strength) {
        int n = workers.size();
        deque<int> dq;
        int i = 0;

        for (int j = n - mid; j < n; ++j) {
            int w = workers[j];
            while (i < mid && tasks[i] <= w + strength) {
                dq.push_back(tasks[i]);
                i++;
            }
            if (dq.empty()) return false;

            if (dq.front() <= w) {
                dq.pop_front();
            } else {
                if (pills == 0) return false;
                pills--;
                dq.pop_back();
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int left = 0, right = min((int)tasks.size(), (int)workers.size());

        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canFinish(mid, tasks, workers, pills, strength)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};