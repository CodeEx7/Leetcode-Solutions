class Solution {
public:
    //Helper DFS function
    void DFS(vector<vector<char>> &grid, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n) return;
        
        if(grid[i][j]=='0' || grid[i][j]=='2') return;
        
        grid[i][j]='2';
        
        DFS(grid,i+1,j,m,n);
        DFS(grid,i,j+1,m,n);
        DFS(grid,i,j-1,m,n);
        DFS(grid,i-1,j,m,n);
    }
    //main working function
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0, m=grid.size(), n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    DFS(grid,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};