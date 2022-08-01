class Solution {
public:
    int helper(vector<int> &nums, int n, vector<int> &memo){
        if(n<0) return 0; 
        if(n==0) return nums[n]; // No more houses left to examine.
        if(memo[n]!=-1) return memo[n];
        
        return memo[n]= max(nums[n]+helper(nums, n-2, memo), helper(nums, n-1, memo));
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n,-1);
        return helper(nums, n-1, memo);
    }
};