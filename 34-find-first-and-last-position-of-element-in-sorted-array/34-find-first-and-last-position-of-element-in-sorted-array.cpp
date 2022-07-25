class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        int res1=-1, res2=-1;
        
        //for finding left most of it
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(target==nums[mid]){
                res1=mid;
                right=mid-1;
            }else if(target>nums[mid]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        //for finding right most of it
        left=0;
        right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(target==nums[mid]){
                res2=mid;
                left=mid+1;
            }else if(target>nums[mid]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return {res1, res2};
    }
};