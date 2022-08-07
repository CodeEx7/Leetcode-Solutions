class Solution {
public:
    //NSL
    void findNSL(vector<int> &nums, vector<int> &NSL){
        stack<pair<int,int>> st;
        for(int i=0;i<nums.size();i++){
            if(st.size()==0) NSL.push_back(-1);
            else if(st.size()>0 && st.top().first<nums[i]){
                NSL.push_back(st.top().second);
            }else if(st.size()>0 && st.top().first>=nums[i]){
                while(st.size()>0 && st.top().first>=nums[i])
                    st.pop();
                if(st.size()==0) NSL.push_back(-1);
                else{
                    NSL.push_back(st.top().second);
            }
        }
            st.push({nums[i],i});
    }
}
    
    //NSR
    void findNSR(vector<int> &nums, vector<int> &NSR){
        stack<pair<int,int>> st;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(st.size()==0) NSR.push_back(n);
            else if(st.size()>0 && st.top().first<nums[i]){
                NSR.push_back(st.top().second);
            }else if(st.size()>0 && st.top().first>=nums[i]){
                while(st.size()>0 && st.top().first>=nums[i])
                    st.pop();
                if(st.size()==0) NSR.push_back(n);
                else if(st.size()>0 && st.top().first<nums[i]){
                    NSR.push_back(st.top().second);
            }
        }
            st.push({nums[i],i});
    }
        reverse(NSR.begin(), NSR.end());
}
    //main working function
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSL;
        vector<int> NSR;
        findNSL(heights, NSL);
        findNSR(heights, NSR);
        
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int val=NSR[i]-NSL[i];
            maxi=max(maxi, heights[i]*(val-1));
        }
       return maxi; 
    }
};