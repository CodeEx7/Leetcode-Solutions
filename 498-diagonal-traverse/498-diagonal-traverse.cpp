class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int n=mat.size();
        int m=mat[0].size();
        map<int, vector<int>> mapp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mapp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto it:mapp){
            if(it.first%2!=0){
                for(int i=0;i<it.second.size();i++){
                    res.push_back(it.second[i]);
                }
            }else{
                int i=it.second.size()-1;
                for(;i>=0;i--){
                    res.push_back(it.second[i]);
                }
            }
        }
        return res;
    }
};