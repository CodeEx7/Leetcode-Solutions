class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        multimap<int, vector<int>> mapp;
        for(auto point:points){
            int dist=pow(point[0],2)+pow(point[1],2);
            mapp.insert({dist,point});
        }
        int i=0;
        for(auto it:mapp){
            res.push_back(it.second);
            i++;
            if(i>=k) break;
        }
        return res;
    }
};