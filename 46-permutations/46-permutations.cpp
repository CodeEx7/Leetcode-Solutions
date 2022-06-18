class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, set<vector<int>> &s, int begin){
        if(begin==nums.size()){
            if(s.find(nums)==s.end()){
                res.emplace_back(nums);
                //s.insert(nums);
                return;
            }
        }
        for(int i=begin; i<nums.size();i++){
            swap(nums[i], nums[begin]);
            backtrack(nums, res, s, begin+1);
            swap(nums[i], nums[begin]);
        }
    }
    //main working function
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        backtrack(nums, res, s, 0);
        return res;
    }
};