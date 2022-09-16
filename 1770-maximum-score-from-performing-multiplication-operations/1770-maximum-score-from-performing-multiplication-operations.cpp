class Solution {
public:
    int helper(int idx, vector<int>& nums, vector<int>& multi, int start, vector<vector<int>> &memo){
        
        if(memo[idx][start]!=INT_MIN) return memo[idx][start];
        
        if(idx==multi.size()) return memo[idx][start]=0;
        
        int end=nums.size()-(idx-start)-1;
        
        
        int op1=multi[idx]*nums[start]+helper(idx+1, nums, multi, start+1, memo);
        int op2=multi[idx]*nums[end]+helper(idx+1, nums, multi, start, memo);
        
        return memo[idx][start]=max(op1, op2);
    }
    //----------------------------------------
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        vector<vector<int>> memo(1001, vector<int>(1001,INT_MIN));
        return helper(0,nums, multi,0, memo);
    }
};