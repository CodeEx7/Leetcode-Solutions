class Solution {
public:
    //backtracking function
    void backtrack(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> combination, int begin){
        if(target==0){
            res.push_back(combination);
            return;
        }
        for(int i=begin;i<candidates.size() && target>=candidates[i];i++){
            if(i==begin || candidates[i]!=candidates[i-1]){
                combination.push_back(candidates[i]);
                backtrack(candidates, target-candidates[i], res, combination, i+1);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, res, combination, 0);
        return res;
    }
};