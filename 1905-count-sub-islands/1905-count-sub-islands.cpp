class Solution {
public:
    //helper function
    void DFS(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        
        if(grid[i][j]==0) return;
        
        grid[i][j]=0;
        
        DFS(grid, i+1, j);
        DFS(grid, i, j+1);
        DFS(grid, i-1, j);
        DFS(grid, i, j-1);
    }
    //main working function
    //sinking the island respectirv to a in b
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(), n=grid1[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==0){
                    DFS(grid2, i, j);
                }
            }
        }
        //counting the remaining island in grid2
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    DFS(grid2, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};