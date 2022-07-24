class Solution {
public:
    //helper function
    void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> &subset, int idx){
        if(idx>=nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        helper(nums, res, subset, idx+1);
        subset.pop_back();
        
        helper(nums, res, subset, idx+1);
    }
    //amin working function
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        helper(nums, res, subset, 0);
        return res;
    }
};