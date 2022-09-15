class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0) return {};
        vector<int> res;
        
        sort(changed.begin(), changed.end());
        
        unordered_map<int,int> mapp;
        for(int i=0;i<changed.size();i++){
            mapp[changed[i]]++;
        }
        
        for(int i=0;i<changed.size();i++){
            if (mapp[changed[i]] == 0) continue;
            if (mapp[changed[i] * 2] == 0) return {};
            res.push_back(changed[i]);
            mapp[changed[i]]--;
            mapp[changed[i] * 2]--;
        }
        return res;
    }
};