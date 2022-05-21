class Solution {
public:
    int helper(vector<int> &nums, int i, int n, vector<int> &memo){
        if(i>=n) return 0;
        if(memo[i]!=-1) return memo[i];
        
        return memo[i]= max(nums[i]+helper(nums, i+2, n, memo), helper(nums, i+1, n, memo));
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n+1,-1);
        return helper(nums, 0, n, memo);
    }
};