class Solution {
public:
    string normalise(string word){
        unordered_map<char, char> mapp;
        char temp='a';
        for(auto ch:word){
            if(mapp.find(ch)==mapp.end()){
                mapp[ch]=temp;
                temp++;
            }
        }
        
        for(int i=0;i<word[i];i++){
            word[i]=mapp[word[i]];
        }
        return word;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string norm_pattern=normalise(pattern);
        
        for(auto word:words){
            if(normalise(word)==norm_pattern){
                res.push_back(word);
            }
        }
        return res;
    }
};