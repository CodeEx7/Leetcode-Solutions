class Solution {
public:
    //helper function
    bool solve(string s1, string s2, string s3, int n1, int n2, int n3, vector<vector<int>> &dp){
        if(n3==0) return 1;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        
        int a,b;
            a=b=0;
        
        if(n1-1>=0 && s1[n1-1]==s3[n3-1]) a=solve(s1,s2,s3,n1-1, n2, n3-1, dp);
        if(n2-1>=0 && s2[n2-1]==s3[n3-1]) b=solve(s1,s2,s3,n1,n2-1, n3-1, dp);
        
        return dp[n1][n2]= a or b;
        
    }
    //main working function
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), n3=s3.size();
        
        if(n3!=(n1+n2)) return false;
        
        vector<vector<int>> dp(101, vector<int> (101, -1));
        
        return solve(s1,s2,s3,n1,n2,n3, dp);
    }
};