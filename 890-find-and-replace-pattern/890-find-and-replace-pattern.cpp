class Solution {
public:
    
    bool check(string &word, string &pattern){
        unordered_map<char, char> w2p;
        unordered_map<char, char> p2w;
        for(int i=0;i<word.size();i++){
            if(w2p.find(word[i])!=w2p.end()){
                if(w2p[word[i]]!=pattern[i]) return false;
            }else{
                w2p.insert({word[i],pattern[i]});
                }
            if(p2w.find(pattern[i])!=p2w.end()){
                if(p2w[pattern[i]]!=word[i]) return false;
            }else{
                p2w[pattern[i]]=word[i];
                }
            }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;   
        for(auto word:words){
            if(word.size()==pattern.size()){
                if(check(word, pattern)==true){
                    res.push_back(word);
                }
            }
        }
        return res;
    }
};