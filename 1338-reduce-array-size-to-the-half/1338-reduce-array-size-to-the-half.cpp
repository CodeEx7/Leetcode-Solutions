class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>> prior;
        unordered_map<int,int> mapp;
        for(auto it:arr){
            mapp[it]++;
        }
        for(auto it:mapp){
            prior.push({it.second,it.first});
            //cout<<it.first<<" "<<it.second<<endl;
        }
        
        int n=arr.size();
        int res=0, cnt=0;
        
        while(!prior.empty()){
            res+=prior.top().first;
            prior.pop();
            cnt++;
            if(res>=n/2) break;
        }
        return cnt;
    }
};