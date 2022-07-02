class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(w);
        verticalCuts.push_back(0);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxh=INT_MIN, maxw=INT_MIN;
        
        for(int i=1;i<horizontalCuts.size();i++){
            maxh=max(maxh, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        for(int i=1;i<verticalCuts.size();i++){
            maxw=max(maxw, verticalCuts[i]-verticalCuts[i-1]);
        }
        
        return (1LL*maxh*maxw)%1000000007;
    }
};