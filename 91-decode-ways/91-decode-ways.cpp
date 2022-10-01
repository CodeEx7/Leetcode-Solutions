class Solution {
public:
    int helper(int i, string s, vector<int> &memo){
        if(s[i]=='0') return 0;
        if(i==s.size()) return 1;
        if(memo[i]!=-1) return memo[i];
        
        int one=helper(i+1, s, memo);
        int two=0;
        
        if(i<s.size()-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<='6')){
            two=helper(i+2, s, memo);
        }
        return memo[i]=one+two;
    }
    //---------------------------
    int numDecodings(string s) {
        vector<int> memo(s.size()+1, -1);
        return helper(0, s, memo);
    }
};