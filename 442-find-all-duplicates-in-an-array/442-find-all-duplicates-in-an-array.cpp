class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> st;
        for(auto it:nums){
            if(st.find(it)!=st.end()){
                res.emplace_back(it);
            }else{
                st.insert(it);
            }
        }
        return res;
    }
};