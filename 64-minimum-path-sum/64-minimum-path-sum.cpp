class Solution {
public:
    //helper function
    int helper(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& memo){
        if(i==0 && j==0) return memo[i][j]=grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(memo[i][j]!=-1) return memo[i][j];
        
        return memo[i][j]=grid[i][j]+ min(helper(grid, i-1, j, m, n, memo),helper(grid, i, j-1, m, n, memo));
    }
    //main working function
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n,-1));
        return helper(grid, m-1, n-1, m, n, memo);
    }
};