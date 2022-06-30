class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini, nums[i]);
        }
        
        for(int i=0;i<n;i++){
            res+=nums[i]-mini;
        }
        return res;
    }
};