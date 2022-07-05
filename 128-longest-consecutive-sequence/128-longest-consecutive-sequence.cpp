class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        int res=0;
        
        for(auto num:nums){
            if(st.find(num-1)==st.end()){
                int currentNum=num;
                int currentStreak=1;
                while(st.find(currentNum+1)!=st.end()){
                    currentNum+=1;
                    currentStreak+=1;
                }
                res=max(res, currentStreak); 
            }               
        }
        return res;
    }
};