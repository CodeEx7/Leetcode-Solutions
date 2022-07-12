class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> mapp;
        for(auto i:intervals){
            mapp[i[0]]++;
            mapp[i[1]]--;
        }
        int cnt=0;
        int res=0;
        
        for(auto it:mapp){
            cnt+=it.second;
            res=max(res, cnt);
        }
       return res; 
    }
};