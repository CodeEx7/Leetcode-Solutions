class Solution {
public:
    int helper(vector<int> &nums, int idx, int n, vector<int> &memo){
        if(idx>=n) return 0;
        if(memo[idx]!=-1) return memo[idx];
        return memo[idx]= max(nums[idx]+helper(nums, idx+2, n, memo), helper(nums, idx+1, n, memo));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> memo1(nums.size()+1, -1);
        vector<int> memo2(nums.size()+1, -1);
        return max(helper(nums, 0, nums.size()-1, memo1), helper(nums, 1, nums.size(), memo2));
    }
};