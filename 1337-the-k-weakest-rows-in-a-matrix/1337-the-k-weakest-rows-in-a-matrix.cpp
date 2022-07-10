class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        for(int i=0;i<mat.size();i++){
            mat[i].push_back(i);
        }
        stable_sort(mat.begin(), mat.end());
        
        vector<int> res(k);
        for(int i=0;i<k;i++){
            res[i]=mat[i][n];
        }
        return res;
    }
};