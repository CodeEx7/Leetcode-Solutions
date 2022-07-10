class Solution {
public:
    //getiing hash Key
    string getHash(string &s){
        string hashKey;
        for (int i = 1; i < s.length(); i++) {
            hashKey += (s[i] - s[i - 1] + 26) % 26 + 'a';
        }
        
        return hashKey;
    }
    //main working function
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mapp;
        for(int i=0;i<strings.size();i++){
            
            string hashkey=getHash(strings[i]);
            
            mapp[hashkey].push_back(strings[i]);
        }
        vector<vector<string>> res;
        for(auto it:mapp){
            res.push_back(it.second);
        }
        return res;
    }
};