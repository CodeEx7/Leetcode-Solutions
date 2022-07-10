class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mapp;
        for(int num:nums){
            mapp[num]++;
        }
        
        for(auto it:mapp){
            pq.push({it.second, it.first});
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};