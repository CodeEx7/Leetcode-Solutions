class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num:nums){
            pq.push(num);
        }
        vector<int> res;
        unordered_map<int, int> mapp;
        while(k--){
            mapp[pq.top()]++;
            pq.pop();
        }
        for(int num:nums){
            if(mapp.find(num)!=mapp.end() && mapp[num]>0){
                res.push_back(num);
                mapp[num]--;
            }
        }
        
        return res;
    }
};