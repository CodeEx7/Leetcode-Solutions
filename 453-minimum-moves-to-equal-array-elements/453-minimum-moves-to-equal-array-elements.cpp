class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            res+=nums[i]-nums[0];
        }
        return res;
    }
};