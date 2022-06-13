class Solution {
public:
    //DFS function
    void DFS(vector<vector<int>>& grid, int i, int j, int &cnt){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        
        if(grid[i][j]==2 || grid[i][j]==0) return;
        
        grid[i][j]=2;
        cnt++;
        
        DFS(grid, i+1, j, cnt);
        DFS(grid, i, j+1, cnt);
        DFS(grid, i-1, j, cnt);
        DFS(grid, i, j-1, cnt);
    }
    //main working function
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(grid[i][j]==1){
                    DFS(grid, i, j, cnt);
                }
                res=max(res, cnt);
            }
        }
        return res;
    }
};