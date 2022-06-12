class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res=0, current_sum=0, start=0;
        unordered_set<int> seen;
        for(int end=0;end<nums.size();end++){
            while(seen.find(nums[end])!=seen.end()){
                seen.erase(nums[start]);
                current_sum-=nums[start];
                start++;
            }
            current_sum+=nums[end];
            seen.insert(nums[end]);
            
            res=max(res, current_sum);
        }
        return res;
    }
};