class Solution {
public:
    //helper function
    int helper(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& memo){
        if(i==m-1 && j==n-1) return memo[i][j]=grid[i][j];
        if(i>=m || j>=n) return INT_MAX;
        if(memo[i][j]!=-1) return memo[i][j];
        
        return memo[i][j]=grid[i][j]+ min(helper(grid, i+1, j, m, n, memo),helper(grid, i, j+1, m, n, memo));
    }
    //main working function
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n,-1));
        return helper(grid, 0, 0, m, n, memo);
    }
};