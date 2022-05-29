class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(mapp.find(nums[i])!=mapp.end()){
                if(abs(mapp[nums[i]]-i) <= k){
                    return true;
                }
            }
            mapp[nums[i]]=i;
        }
        return false;
    }
};