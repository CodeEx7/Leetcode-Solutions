class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return 1;
        int res;
        int prev=nums[1]-nums[0];
        if(prev==0){
            res=1;
        }else{
            res=2;
        }
        for(int i=2;i<nums.size();i++){
            int diff=nums[i]-nums[i-1];
            if((diff>0 && prev<=0) || (diff<0 && prev>=0)){
                res++;
                prev=diff;
            }
        }
        return res;
    }
};