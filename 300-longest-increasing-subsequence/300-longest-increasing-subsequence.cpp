class Solution {
public:
    int ceilIdx(vector<int> &tail, int target){
        int left=0, right=tail.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(tail[mid]>=target){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return right;
    }
    //--------------------------------
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        tail.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>tail.back()){
                tail.push_back(nums[i]);
            }else{
                int idx=ceilIdx(tail, nums[i]);
                tail[idx]=nums[i];
            }
        }
        return tail.size();
    }
};