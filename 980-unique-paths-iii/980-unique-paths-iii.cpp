class Solution {
public:
    //helper function
    int helper(vector<vector<int>>& grid, int x, int y, int zeros){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==-1){
            return 0;
        }
        if(grid[x][y]==2)
            return zeros==-1?1:0;
        grid[x][y]=-1;
        zeros--;
        int totalPath=helper(grid, x+1, y, zeros)+
                        helper(grid, x, y+1, zeros)+
                        helper(grid, x-1, y, zeros)+
                        helper(grid, x, y-1, zeros);
        grid[x][y]=0;
        zeros++;
        
        return totalPath;
        
    }
    //main working function
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int sx, sy, ex, ey, zeros=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    sx=i; sy=j;
                }else if(grid[i][j]==0){
                    zeros++;
                }
            }
        }
       return helper(grid, sx, sy, zeros);
    }
};