class Solution {
public:
    char shiftLetter(char letter, int shift) {
        return (letter - shift + 26) % 26 + 'a';
    }
    //getiing hash Key
    string getHash(string s){
        int shift = s[0];
        string hashKey;
        
        for (char letter : s) {
            hashKey += shiftLetter(letter, shift);
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