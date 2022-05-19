class Solution {
public:
   int dfs(int i,int j,vector<vector<int>>& matrix,int prev, vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(i<0||j<0||i>=n||j>=m||matrix[i][j]<=prev){
            return 0;
        }
       
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
      int up=dfs(i-1,j,matrix,matrix[i][j], dp);
      int down=dfs(i+1,j,matrix,matrix[i][j], dp);
      int right=dfs(i,j+1,matrix,matrix[i][j], dp);
      int left=dfs(i,j-1,matrix,matrix[i][j], dp);
        return dp[i][j]= max(max(up,down),max(right,left))+1;
        
        
    }
    //main working function
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(201, vector<int>(201,-1));
        
        int max_path=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              max_path=max (max_path,dfs(i,j,matrix,-1, dp));
            }
        }
      return max_path;
    }
};
