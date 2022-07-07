class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        
        //if anyone word is empty
        if(n==0 || m==0) return n+m;
        
        //dp array
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        
        //base cases
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<m+1;i++){
            dp[0][i]=i;
        }
        
        //compute the DP values
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int left=dp[i-1][j]+1;
                int down=dp[i][j-1]+1;
                int left_down=dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1]){
                    left_down+=1;
                }
                dp[i][j]=min(left, min(down, left_down));
            }
        }
        return dp[n][m];
    }
};