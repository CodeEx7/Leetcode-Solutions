class Solution {
public:
    int climb_stairs(int i, int n, vector<int> &memo){
        if(i>n) return 0;
        if(i==n) return 1;
        if(memo[i]!=-1) return memo[i];
        
        return memo[i] = climb_stairs(i+1,n, memo)+climb_stairs(i+2,n, memo);
    }
    
    int climbStairs(int n) {
        vector<int> memo(n, -1);
        return climb_stairs(0,n, memo);
    }
};