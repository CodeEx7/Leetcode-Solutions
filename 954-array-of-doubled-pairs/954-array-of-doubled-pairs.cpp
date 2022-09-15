class Solution {
public:  
    
    static bool compare(int a,int b){
        return abs(a)<abs(b);
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        if(arr.size()%2!=0) return {};
        vector<int> res;
        
        sort(arr.begin(), arr.end(), compare);
        
        unordered_map<int,int> mapp;
        for(int i=0;i<arr.size();i++){
            mapp[arr[i]]++;
        }
        
        for(int i=0;i<arr.size();i++){
            if (mapp[arr[i]] == 0) continue;
            if (mapp[arr[i] * 2] == 0) return {};
            res.push_back(arr[i]);
            mapp[arr[i]]--;
            mapp[arr[i] * 2]--;
        }
        return res.size()==arr.size()/2;
    }
};