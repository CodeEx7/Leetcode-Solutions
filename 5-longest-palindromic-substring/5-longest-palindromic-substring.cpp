class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return "";
        
        vector<vector<int>> dp(n, vector<int> (n,0));
        //filling thr Diagonal
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int start=0, end=1;
        //filling second upper diagonal
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                start=i, end=2;
            }
        }
        //filling remaining upper part
        for(int j=2;j<n;j++){
            for(int i=0;i< n-j;i++){  
                int left=i; //start point
                int right = i+j;  //ending point
                if(dp[left+1][right-1]==1 && s[left]==s[right]){
                    dp[left][right]=1; 
                    start=i; 
                    end=j+1; 
            }        
        }
    }
    return s.substr(start, end);
    }
}; 