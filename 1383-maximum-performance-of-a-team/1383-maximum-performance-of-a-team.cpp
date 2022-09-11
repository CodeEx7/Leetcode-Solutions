class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        vector<pair<int,int>> engineers;
        for (int i = 0; i < n; ++i)
            engineers.emplace_back(efficiency[i], speed[i]);
        
        sort(engineers.begin(), engineers.end(), greater()); // Sort by decreasing order of efficiency
        long speedSum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto it: engineers) {
            speedSum += it.second;
            minHeap.emplace(it.second);
            if (minHeap.size() > k) { // Over k engineers -> remove the lowest speed engineer
                speedSum -= minHeap.top();
                minHeap.pop();
            }
            ans = max(ans, speedSum * it.first);
        }
        return ans % (int) (1e9 + 7);
    }
};