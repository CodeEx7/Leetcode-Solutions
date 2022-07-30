class Solution {
public:
    //issubset function
    bool isSubset(string word, vector<char> cnt){
        vector<char> curr(26, 0);
        for(auto ch: word){
            curr[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(curr[i]<cnt[i]){
                return false;
            }
        }
        return true;
    }
    //super set function
    void super(string word, vector<char> &cnt){
        vector<char> curr(26,0);
        for(auto ch:word){
            curr[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            cnt[i]=max(cnt[i], curr[i]);
        }
    }
    //main working function
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        string superset="";
        vector<char> cnt(26,0);
        //mapping first word
        for(auto ch:words2[0]){
            cnt[ch-'a']++;
        }
        //for remaining word
        for(int i=1;i<words2.size();i++){
            super(words2[i], cnt);
        }
        
        //comparing with each word of words1 array
        for(auto word:words1){
            if(isSubset(word, cnt)==true){
                res.push_back(word);
            }
        }
        return res;
    }
};