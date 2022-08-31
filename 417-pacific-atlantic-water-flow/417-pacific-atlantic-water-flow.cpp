class Solution {
public:
    //helper DFS function
    void DFS(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>> &ocean ){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || heights[i][j]<prev) return;
        
        if(ocean[i][j]==1) return;
        
        ocean[i][j]=1;
        
        prev=heights[i][j];
        
        DFS(heights, i+1, j, prev, ocean);
        DFS(heights, i, j+1, prev, ocean);
        DFS(heights, i-1, j, prev, ocean);
        DFS(heights, i, j-1, prev, ocean);
    }
    
    //main working function
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> Pac(n,vector<int>(m,0));
        vector<vector<int>> Atl(n,vector<int>(m,0));
        vector<vector<int>> res;
        
        for(int row=0;row<n;row++){
            DFS(heights, row, 0, INT_MIN, Pac);
            DFS(heights, row, m-1, INT_MIN, Atl);
        }
        
        for(int col=0;col<m;col++){
            DFS(heights, 0, col, INT_MIN, Pac);
            DFS(heights, n-1, col, INT_MIN, Atl);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Pac[i][j]==1 && Atl[i][j]==1){
                    res.push_back({i,j});
                }
            }
        }
        
        
        return res;
    }
};