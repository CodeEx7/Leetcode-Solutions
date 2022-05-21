class Solution {
public:
    int helper(vector<int> &nums, int i, int n, vector<int> &memo){
        if(i>=n) return 0;
        
        if(memo[i]!=-1) return memo[i];
        
        return memo[i] = max(nums[i]+helper(nums, i+2, n, memo), helper(nums, i+1, n, memo));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> memo1(n+1,-1);
        vector<int> memo2(n+1,-1);
        return max(helper(nums, 0, n-1, memo1), helper(nums, 1, n, memo2));
    }
};