class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        unordered_map<char, int> mapp;
        
        for(int i=0;i<s.size();i++){
            mapp[s[i]-'a']++;
            mapp[t[i]-'a']--;
        }
        
        for(auto it:mapp){
            if(it.second!=0) return false;
        }
        return true;
    }
};