class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        int res=0;
        unordered_map<char, int> smapp;
        for(char c:s){
            smapp[c]++;
        }
        for(auto e:smapp)
        {
            if(e.second%2==0)
                res+=e.second;
            else if(e.second%2!=0 && e.second>2)
                res+=(e.second-1);
        }
        if(res!=n)
            return res+1;
        else
            return res;
    }
};