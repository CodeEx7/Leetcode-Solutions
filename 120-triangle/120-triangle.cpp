class Solution {
public:
    int helper(int i, int j, int n, vector<vector<int>> &tringle,vector<vector<int>> &memo){
        if(i==n-1) return tringle[i][j];
        if(memo[i][j]!=-1) return memo[i][j];
        return memo[i][j]=tringle[i][j]+min(helper(i+1,j,n,tringle, memo), helper(i+1,j+1,n,tringle, memo));
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return helper(0,0,n, triangle, memo);
    }
};