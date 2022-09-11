class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        vector<vector<int>> engineers;
        for (int i = 0; i < n; ++i)
            engineers.push_back({efficiency[i], speed[i]});
        
        sort(rbegin(engineers), rend(engineers)); // Sort by decreasing order of efficiency
        long speedSum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto it: engineers) {
            speedSum += it[1];
            minHeap.emplace(it[1]);
            if (minHeap.size() > k) { // Over k engineers -> remove the lowest speed engineer
                speedSum -= minHeap.top();
                minHeap.pop();
            }
            ans = max(ans, speedSum * it[0]);
        }
        return ans % (int) (1e9 + 7);
    }
};