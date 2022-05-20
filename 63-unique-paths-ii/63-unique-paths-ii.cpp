class Solution {
public:
    //helper function
    int helper(vector<vector<int>> &grid, vector<vector<int>> &memo, int i, int j, int m, int n){
        if(i==m-1 && j==n-1 && grid[m-1][n-1]!=1) return 1;
        if(i>=m || j>=n || grid[i][j]==1) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        
        return memo[i][j]=helper(grid, memo,i+1,j,m,n)+helper(grid, memo,i,j+1,m,n);
        
    }
    //main working function
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n,-1));
        return helper(obstacleGrid, memo, 0,0,m,n);
    }
};