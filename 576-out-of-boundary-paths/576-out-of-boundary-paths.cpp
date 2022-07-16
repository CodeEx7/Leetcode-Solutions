class Solution {
public:
    //helper function
    int memo[51][51][51];
    long long int mod = pow(10, 9) + 7;
    
    int helper(int m, int n, int N, int i, int j){
        if(i==m || j==n || i<0 || j<0) return 1;
        
        if(N==0) return 0;
        
        if(memo[i][j][N]!=-1) return memo[i][j][N];
        
        int right=helper(m,n,N-1,i+1,j);
        int left=helper(m,n,N-1,i-1,j);
        int down=helper(m,n,N-1,i,j-1);
        int up=helper(m,n,N-1,i,j+1);
                   
    return memo[i][j][N]= (right%mod+up%mod+down%mod+left%mod)%mod;
    }
    
    
    //main working function
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo, -1, sizeof(memo));
        return helper(m,n,maxMove,startRow,startColumn);
    }
};