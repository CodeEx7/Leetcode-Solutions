class Solution {
public:
    //finding next greater element
    void findNGE(vector<int> nums, vector<int> &res){
        stack<int> st;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()) res.push_back(-1);
            else if(st.size()>0 and st.top()>nums[i]){
                res.push_back(st.top());
            }else if(st.size()>0 && st.top()<=nums[i]){
                while(st.size()>0 && st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty()) res.push_back(-1);
                else if(st.size()>0 and st.top()>nums[i]){
                res.push_back(st.top());
            }
        }
            st.push(nums[i]);
    }
   reverse(res.begin(), res.end());             
}
    //main working function
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> NGE, res;
        findNGE(nums2,NGE);
        unordered_map<int,int> mapp;
        for(int i=0;i<nums2.size();i++){
            mapp[nums2[i]]=i;
        }
        for(auto num:nums1){
            res.push_back(NGE[mapp[num]]);
        }
        return res;
    }
};