class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int> mapp;
        for(auto ch:magazine){
            mapp[ch]++;
        }
        
        for(auto ch:ransomNote){
            if(mapp.find(ch)==mapp.end()){
                return false;
            }else{
                if(mapp[ch]<=0){
                    return false;
                }else{
                    mapp[ch]--;
                }
            }
        }
        return true;
    }
};