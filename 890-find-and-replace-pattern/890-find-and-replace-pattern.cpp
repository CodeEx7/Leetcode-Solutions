class Solution {
public:
    //normalise function
    string normalise(string word){
        char c='a';
        unordered_map<char, char> mapp;
        for(auto ch:word){
            if(mapp.find(ch)==mapp.end()){
                mapp[ch] = c;
                c++;
            }
        }
        for(int i=0;i<word.size();i++){
            word[i]=mapp[word[i]];
        }
        return word;
    }
    //main working function
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