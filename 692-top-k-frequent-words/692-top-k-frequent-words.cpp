class Solution {
public:
    //mycmp function
    static bool mycmp(const pair<int, string> &p1, const pair<int, string> &p2){
        if(p1.first>p2.first ||(p1.first==p2.first && p1.second<p2.second))
            return true;
        return false;
    }
    //main working function
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mapp;
        for(auto word:words){
            mapp[word]++;
        }
        vector<pair<int, string>> arr;
        for(auto it:mapp){
            arr.push_back({it.second, it.first});
        }
        
        sort(arr.begin(), arr.end(), mycmp);
        
        vector<string> res;
        for(int i=0;i<k;i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};