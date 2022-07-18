class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int pre_sum=0, res=0;
        unordered_map<int,int> mapp;
        for(int i=0;i<nums.size();i++){
            pre_sum+=nums[i];
            if(pre_sum==k){
                res++;
            }
            if(mapp.find(pre_sum-k)!=mapp.end()){
                res+=mapp[pre_sum-k];
            }
            mapp[pre_sum]++;
        }
        return res;
    }
};