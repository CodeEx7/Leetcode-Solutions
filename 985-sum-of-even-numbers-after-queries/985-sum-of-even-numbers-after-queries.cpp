class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int even_sum=0;
        for(int num:nums){
            if(num%2==0){
                even_sum+=num;
            }
        }
        for(int i=0;i<queries.size();i++){
            int idx=queries[i][1];
            int val=queries[i][0];
            
            if(nums[idx]%2==0){
                even_sum-=nums[idx]; 
            }
            nums[idx]=nums[idx]+val;         
            if(nums[idx]%2==0){
                even_sum+=nums[idx];
            }
            res.push_back(even_sum);
        }
        return res;
    }
};