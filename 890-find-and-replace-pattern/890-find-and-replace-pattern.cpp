class Solution {
public:
    string normalise(string word){
        unordered_map<char, char> mapp;
        char c='a';
        for(auto ch:word){
            if(mapp.find(ch)==mapp.end()){
                mapp[ch]=c;
                c++;
            }
        }
        
        for(int i=0;i<word.size();i++){
            word[i]=mapp[word[i]];
        }
        return word;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string normalise_pattern=normalise(pattern);
        
        for(auto word:words){
            if(normalise(word)==normalise_pattern){
                res.push_back(word);
            }
        }
        return res;
    }
};