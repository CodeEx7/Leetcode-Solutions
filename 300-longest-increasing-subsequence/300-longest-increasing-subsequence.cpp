class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(),0);
        
        for(int i=0;i<nums.size();i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        int res=0;
        for(auto it:lis){
            res=max(res,it);
        }
        return res;
    }
};