class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mapp;
        for(auto str:strs){
            string temp=str;
            sort(temp.begin(), temp.end());
            mapp[temp].push_back(str);
        }
        for(auto it:mapp){
            res.push_back(it.second);
        }
        return res;
    }
};