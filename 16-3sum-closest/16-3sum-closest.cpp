class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int mini=INT_MAX, res=0;
        
        for(int i=0;i<nums.size();i++){
            int start=i+1, end=nums.size()-1;
            while(start<end){
                int curr_sum;
                if(i!=start && i!=end){
                    curr_sum=nums[i]+nums[start]+nums[end];
                    int abs_val=abs(curr_sum-target);
                    
                    if(abs_val<mini){
                        res=curr_sum;
                        mini=abs_val;
                    }
                }
                if(curr_sum<target){
                    start++;
                }else{
                   end--; 
                }
            }
        }
        return res;
    }
};