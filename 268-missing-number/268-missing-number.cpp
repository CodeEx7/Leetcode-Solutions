class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missi=0;int i=0;
        for( ;i<nums.size();i++){
            missi=missi^i^nums[i];
        }
        return missi^i;
    }
};