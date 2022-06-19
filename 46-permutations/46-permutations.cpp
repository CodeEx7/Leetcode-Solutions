class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, int begin){
        if(begin==nums.size()){
                res.emplace_back(nums);
                return;
        }
        for(int i=begin; i<nums.size();i++){
            swap(nums[i], nums[begin]);
            backtrack(nums, res, begin+1);
            swap(nums[i], nums[begin]);
        }
    }
    //main working function
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(nums, res, 0);
        return res;
    }
};