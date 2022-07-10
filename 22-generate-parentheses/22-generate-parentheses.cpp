class Solution {
public:
    //helper function
    void helper(int open, int close, int n, string curr, vector<string> &res){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n) helper(open+1, close, n, curr+'(', res);
        if(close<open) helper(open, close+1, n, curr+')', res);
    }
    //working function
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr="";
        helper(0,0,n,curr,res);
        return res;
    }
};