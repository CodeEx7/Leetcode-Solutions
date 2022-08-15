class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char, int> stov{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res=0, prev_max=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(stov[s[i]]<prev_max){
                res-=stov[s[i]];
            }else{
                res+=stov[s[i]];
            }
                prev_max=stov[s[i]];
        }
        return res;
    }
};