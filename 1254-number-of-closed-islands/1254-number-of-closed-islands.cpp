class Solution {
public:
    //DFS function
    void DFS(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        
        if(grid[i][j]==1 || grid[i][j]==1) return;
        
        grid[i][j]=1;
        
        DFS(grid, i+1, j);
        DFS(grid, i, j+1);
        DFS(grid, i-1, j);
        DFS(grid, i, j-1);
    }
    //main working function
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), res=0;
        
        //filling the boundries 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    DFS(grid, i, j);
                }
            }
        }
        
        //counting the closed islands
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    DFS(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};