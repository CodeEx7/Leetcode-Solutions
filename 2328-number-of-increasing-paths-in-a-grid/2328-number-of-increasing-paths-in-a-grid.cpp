class Solution {
public:
    
    //DFS Function
    int DFS(int i, int j, int m, int n, vector<vector<int>> &grid, int prev, vector<vector<int>> &memo){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]<=prev) return 0;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        return memo[i][j]= 1+DFS(i+1,j,m,n, grid, grid[i][j], memo)%1000000007+
               DFS(i,j+1,m,n, grid, grid[i][j], memo)%1000000007+
               DFS(i-1,j,m,n, grid, grid[i][j], memo)%1000000007+
                DFS(i,j-1,m,n, grid, grid[i][j], memo)%1000000007;
    }
    //main working function
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> memo(1000, vector<int>(1000, -1));
        long long res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res+=DFS(i,j,m,n, grid, INT_MIN, memo)%1000000007;
            }
        }
       return res%1000000007; 
    }
};