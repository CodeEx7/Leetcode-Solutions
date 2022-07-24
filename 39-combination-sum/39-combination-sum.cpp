class Solution {
public:
    //helper function
    void helper(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &combination, int begin){
        
        if(begin==candidates.size()){
            if(target==0){
                res.push_back(combination);
            }
            return;
        }
        //picking up the element
        if(target>=candidates[begin]){
            combination.push_back(candidates[begin]);
            helper(candidates, target-candidates[begin], res, combination, begin);
            combination.pop_back();
        }
        helper(candidates, target, res, combination, begin+1);
    }
    //main working function
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        //sort(candidates.begin(), candidates.end());
        helper(candidates, target, res, combination, 0);
        return res;
    }
};