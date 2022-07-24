class Solution {
public:
    //helper function
    void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> subset, int idx, set<vector<int>> &unique){
        if(idx==nums.size()){
            sort(subset.begin(), subset.end());
            if(unique.find(subset)==unique.end())
                res.push_back(subset);
            unique.insert(subset);
            return;
        }
        subset.push_back(nums[idx]);
        helper(nums, res, subset, idx+1, unique);
        subset.pop_back();
        
        helper(nums, res, subset, idx+1, unique);
    }
    //main working function;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        set<vector<int>> unique;
        helper(nums, res, subset, 0, unique);
        return res;
    }
};