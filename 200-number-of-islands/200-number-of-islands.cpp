class Solution {
public:
    //DFS function
    void DFS(int i, int j, int m, int n, vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='1') return ;
        
        grid[i][j]='2';
        
        DFS(i+1,j,m,n,grid);
        DFS(i,j+1,m,n,grid);
        DFS(i-1,j,m,n,grid);
        DFS(i,j-1,m,n,grid);
    }
    //main working function
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    DFS(i,j,m,n, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};