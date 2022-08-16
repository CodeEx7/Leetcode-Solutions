class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mapp;
        for(auto ch:s){
            mapp[ch]++;
        }
        int res=-1;
        for(int i=0;i<s.size();i++){
            if(mapp[s[i]]==1){
                res=i;
                break;
            }
        }
      return res;
    }
};