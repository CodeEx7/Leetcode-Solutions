class Solution {
public:
    int find_next(vector<int> &nums, int idx, int target){
        for(int i=idx;i<nums.size();i++){
            if(nums[i]>target){
                return nums[i];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    res.push_back(find_next(nums2, j, nums2[j]));
                }
            }
        }
        return res;
    }
};