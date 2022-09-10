class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_stock=INT_MAX;
        int res=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>min_stock){
                res=max(res,nums[i]-min_stock);
            }else{
                min_stock=min(min_stock,nums[i]);
            }
        }
        return res;
    }
};