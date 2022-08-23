class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        nums.clear();
        for(auto it:s){
            nums.push_back(it);
        }
        int cmp=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                continue;
            }else{
                if(nums[i]!=cmp){
                    return cmp;
                }
                cmp++;
            }
        }
        return cmp++;
    }
};