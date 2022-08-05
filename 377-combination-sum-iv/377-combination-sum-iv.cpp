class Solution {
public:
    int solve(vector<int>&nums,int target,vector<int>&dp){
        //base condition
        if(target<0)return 0;
        if(target==0)return 1;
        //check the cache
        if(dp[target]!=-1)return dp[target];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(target>=nums[i])
                ans+=solve(nums,target-nums[i],dp);
        }
        return  dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int t) {
        int n=nums.size();
        vector<int>dp(t+1,-1);
        return solve(nums,t,dp);
    }
};