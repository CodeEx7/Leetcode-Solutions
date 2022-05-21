class Solution {
public:
    int solve_tabulation(vector<int> &wt, int amt, int n){
        int dp[amt + 1][n + 1];
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i< amt + 1;i++){
            for(int j = 0;j<n + 1;j++){
                if(i == 0 || j == 0){
                    if(i == 0)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = INT_MAX - 1;
                }
            }
        }
        for(int i = 1;i<amt + 1;i++){
            for(int j = 1;j<n + 1;j++){
                if(wt[j-1] > i)
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = min(dp[i][j-1], 1 + dp[i - wt[j-1]][j]);
            }
        }
        return dp[amt][n];
   }		

	 int coinChange(vector<int>& coins, int amount) {
        int ans = solve_tabulation(coins, amount, coins.size());
        if(ans == INT_MAX - 1)
            return -1;
        return ans;
    }
};