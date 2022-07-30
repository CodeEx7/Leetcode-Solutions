class Solution {
public:
    bool isSubset(string word1, string word2){
        unordered_map<char,int> mapp;
        for(auto ch:word1){
            mapp[ch]++;
        }
        
        for(auto ch:word2){
            if(mapp.find(ch)!=mapp.end()){
                mapp[ch]--;
                if(mapp[ch]==0) mapp.erase(ch);
            }else{
                return false;
            }             
        }
        return true;
    }
    
    void make_super(string word, unordered_map<char,int> &mapp){
        unordered_map<char, int> curr;
        for(auto ch:word){
            curr[ch]++;
        }
        for(auto it:curr){
            if(mapp.find(it.first)==mapp.end()){
                mapp.insert({it.first, it.second});
            }else{
                mapp[it.first]=max(mapp[it.first], curr[it.first]);
            }
        }
    }
    //main working function
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        string super="";
        unordered_map<char, int> mapp;
        for(auto ch:words2[0]){
            mapp[ch]++;
        }
        for(int i=1;i<words2.size();i++){
            make_super(words2[i], mapp);
        }
        
        for(auto it:mapp){
            while(it.second--){
                super+=it.first;
            }
        }
        
        for(auto word1:words1){
            if(isSubset(word1, super)==true){
                res.push_back(word1);
            }
        }
        return res;
    }
};