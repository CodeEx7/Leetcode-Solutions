class Solution {
public:
        //NSL nearest smaller left
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
    
    //NSR nearest smaller right
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
    //MAH working function
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSL;
        vector<int> NSR;
        findNSL(heights, NSL);
        findNSR(heights, NSR);
        
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi, heights[i]*(NSR[i]-NSL[i]-1));
        }
       return maxi; 
    }
    //main working function
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int> heights(m,0);
        int maxi=INT_MIN;
        
        for(int i=0;i<m;i++){
            if(matrix[0][i]=='1')
            heights[i]+=1;
        }
        maxi=largestRectangleArea(heights);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]+=1;
                }else{
                    heights[j]=0;
                }
            }
            maxi=max(maxi, largestRectangleArea(heights));
        }
        return maxi;
    }
};