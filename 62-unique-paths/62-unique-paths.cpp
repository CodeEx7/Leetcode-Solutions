class Solution {
public:
    //helper function
    int helper(vector<vector<int>> &memo, int m, int n, int i, int j){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        
        return memo[i][j]=helper(memo,m,n, i+1, j)+helper(memo,m,n, i, j+1);
    }
    //main working function
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int> (n, -1));
        return helper(memo, m, n, 0, 0);
         
    }
};