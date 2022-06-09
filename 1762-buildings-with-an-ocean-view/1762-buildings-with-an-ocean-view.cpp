class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int n=heights.size();
        int max_height=heights[n-1];
        res.push_back(n-1);
        for(int i=n-1;i>=0;i--){
            if(heights[i]>max_height){
                max_height=heights[i];
                res.push_back(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};