class Solution {
public:
    //helper function
    bool helper(string word, unordered_map<char, vector<int>> &mapp){
        int prev_idx=-1;
        for(int i=0;i<word.size();i++){
            if(mapp.find(word[i])==mapp.end()) return false;
            
            auto it=upper_bound(mapp[word[i]].begin(), mapp[word[i]].end(), prev_idx);
            
            if(it==mapp[word[i]].end()) return false;
            
            prev_idx=*it;
        }
        return true;
    }
    //main working function
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mapp;
        for(int i=0;i<s.size();i++){
            mapp[s[i]].push_back(i);
        }
        int cnt=0;
        for(auto word:words){
            if(helper(word, mapp)==true){
                cnt++;
            }
        }
        return cnt;
    }
};